//LOGGING SYSTEM TO ENABLE AND DISABLE DEBUGPRINT.#if 1 to enable, #if 0 to disable debugprint
#if 0
	#define DEB(a) printf a
#else
	#define DEB(a) (void)0
#endif
//Statement format is DEB(("Debug: "));


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>
#include <regex.h>
#include <ctype.h>

#include "flags.h"
#include "queue.h"
#include "stack.h"
#include "ftw.h"

#define EXOR(a, b) (((a) && !(b)) || (!(a) && (b)))
#define MAXSEARCH 32

//return values of grep
#define FOUND 0
#define NOTFOUND 1
#define FILEERR 2
#define USAGEERR 3

int is_text(char *filename);
int readline(FILE *f, char *buffer, size_t len);
char *strcasestr(const char *haystack, const char *needle);

int main(int argc, char *argv[]) {
	//declarations
	FILE *patternfile, *fp;
	char *search = (char *)malloc(128), *filename, *line = (char *)malloc(256);
	int count = 0, printffilenameonceifflagc = 1, insensitive;
	long byteoffset = 0;
	queue filequeue;
	qinit(&filequeue);


	//initialize flags
	flaginit();
	insensitive = flag.i;

	//fetch options
	flagset(argc, argv);//read options
	if(flag.exit)
		return USAGEERR;
	
	//checkflagstatus
	//flagstatus();

	//open patternfile which either contains files from flag.f_arg or strings manually added to the file in flags.c
	patternfile = fopen("patternfile.txt", "r+");
	if(patternfile == NULL) {
		fprintf(stderr, "%s: No such file or directory\n", flagf_arg());
		return FILEERR;
	}

	while(readline(patternfile, search, 128) > 0)
		DEB(("Patternfile line: %s\n", search));
	DEB(("\n"));
	fseek(patternfile, 0, SEEK_SET);

	//If rescursive is specified, add files to queue using appropriate code
	if(flag.r) {
		if (print_directory_tree(".")) {
			fprintf(stderr, "%s.\n", strerror(errno));
			return FILEERR;
		}
		fp = fopen("./filequeue", "r");
		while(fgets(line, 255, fp) != 0) {
			DEB(("Enqueueing %s", line));
			enqueue(&filequeue, line);
		}
		fclose(fp);
		remove("./filequeue");
	}
	//if searchfile if present, add searchfile to queue
	else if(flag.searchfile) {
		enqueue(&filequeue, flagsearchfile_arg());
	}
	//if not recursive and no searchfile specified, add stdin to queue
	else { // if(!flag.r and !flag.searchfile) then use stdin;
		enqueue(&filequeue, "stdin");
	}
	//make list for patternfile
	//open patternfile if present
	

	
	

	//SEARCH ALGORITHM:

	while(!qisempty(&filequeue)) {
		filename = dequeue(&filequeue);
		DEB(("OPEN: %s\n", filename));
		if(strcmp(filename, "stdin") == 0) 
			fp = stdin;//operate using stdin
		else if(strcmp(filename, "filequeue") == 0)
			continue;
		else if(strcmp(filename, "patternfile.txt") == 0)
			continue;
		/*else if((is_text(filename) == 0)) {
			if(!flag.q && flag.r);
				printf("%s is Binary\n", filename);
			continue;
		}*/
		else {
			fp = fopen(filename, "r");
			if(fp == NULL) {
				fprintf(stderr, "File could not be opened\n");
				return FILEERR;
			}
		}
		count = 0;
		if(flag.c && flag.r && !flag.h && !flag.q) {
			printf("%s:", filename);
			printffilenameonceifflagc--;
		}
		while(!feof(fp)) {
			byteoffset = ftell(fp);//insert fseek to get current byte offset of line
			if(fgets(line, 256, fp) == NULL)//if eof, break directly
				break;
			while(readline(patternfile, search, 128) > 0) { //condition to cpy pattern into *search from file line by line and then close and reopen file
				//if(EXOR(((insensitive == 0)? strstr(line, search) : strcasestr(line, search)), flag.v)) {//modify for case sensitive flag
				//char *x = ((insensitive == 0)?strstr(line, search) : strcasestr(line, search));
				char *x;
				if(insensitive == 0)
					x = strstr(line, search);
				else
					x = strcasestr(line, search);
				
				if(EXOR(x, flag.v)) {//modify for case sensitive flag
					if(flag.H && (strcmp(filename, "stdin") != 0) && (flag.q != 1) && printffilenameonceifflagc) {//printing filename
						printf("%s:", filename);
						if(flag.c)
							printffilenameonceifflagc--;
					}
					if(flag.q)//quit if match + flag.q set
						return FOUND;
					if(flag.b && !flag.c)//print byteoffset if flag.b
						printf("%ld:", byteoffset);
					if(flag.c && flag.v) {//if flag.c, we need to suppress line printing. Dont bother with flag.q as already handled
						++count;
						break;
					}
					else;
					if(!flag.c) {//if flag.c, we need to suppress line printing. Dont bother with flag.q as already handled
						printf("%s", line);
						break;
					}
				}
			}
			fseek(patternfile, 0, SEEK_SET);
			if(flag.m && (count == flagm_arg()))//terminate program if flag.m and sufficient (nummatch) matches are found
				return FOUND;
		}
		if(flag.c && !flag.q)//print count if flag.c and not quiet mode
			printf("%d\n", count);
		printffilenameonceifflagc = 1;
		fclose(fp);
		free(filename);
	}

	free(search);
	free(line);
	fclose(patternfile);
	remove("./patternfile.txt");
	if(count > 0)
		return FOUND;

	return NOTFOUND;
}

int readline(FILE *f, char *buffer, size_t len) {
	char c; 
	int i;
	memset(buffer, 0, len);
	for (i = 0; i < len; i++) {
		c = fgetc(f);
		if (!feof(f)) {
			if (c == '\n')	{
				buffer[i] = '\0';
				return i;
			}
			else
				buffer[i] = c;
		}
		else
			return -1;
	}

	return -1; 
}

int is_text(char *filename) {
	FILE *f = fopen(filename, "r");
	if (!f) {
		perror("fopen failed");
		return 0;
	}
	int c;
	while ((c=fgetc(f) != EOF))
		if ((!isascii(c) || iscntrl(c)) && !isspace(c)) {
			fclose(f);
			return 0;
		}
	return 1;
	fclose(f);
}
