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

#include "flags.h"
#include "queue.h"
#include "stack.h"

#define EXOR(a, b) (((a) && !(b)) || (!(a) && (b)))
#define MAXSEARCH 32


//LOGGING SYSTEM TO ENABLE AND DISABLE DEBUGPRINT.#if 1 to enable, #if 0 to disable debugprint
#if 0
	#define DEB(a) printf a
#else
	#define DEB(a) (void)0
#endif
//Statement format is DEB(("Debug: "));

//return values of grep
#define FOUND 0
#define NOTFOUND 1
#define FILEERR 2
#define USAGEERR 3

int main(int argc, char *argv[]) {
	//declarations
	FILE *patternfile, *fp;
	char *search = (char *)malloc(128), *filename, *line = (char *)malloc(256);
	int count = 0;
	long byteoffset = 0;
	queue filequeue;
	qinit(&filequeue);

	//initialize flags
	flaginit();
	//fetch options
	flagset(argc, argv);//read options
	
	if(flag.exit)
		return USAGEERR;
	
	//printstatus
	//flagstatus();

	//if searchfile if present, add searchfile to queue
	if(flag.searchfile) {
		enqueue(&filequeue, flagsearchfile_arg());
	}
	//If rescursive is specified, add files to queue using appropriate code
	//if not recursive and no searchfile specified, add stdin to queue

	//make list for patternfile
	//open patternfile if present
	

	/*if(flag.e)//IMPLEMENT REGEX HERE
		strcpy(search, flage_arg());*/
	
	

	//SEARCH ALGORITHM:

	strcpy(search, flagexp_arg());//get search argument if patternfile is not supplied

	while(!qisempty(&filequeue)) {
		filename = dequeue(&filequeue);
		DEB(("1Debug: filename dequeued = %s\n", filename));
		if(strcmp(filename, "stdin") == 0) 
			return NOTFOUND;//CHANGE CODE HERE //dont open but operate using stdin
		else {
			fp = fopen(filename, "r");
			if(fp == NULL)
				return FILEERR;
		}
		count = 0;
		while(!feof(fp)) {
			byteoffset = ftell(fp);//insert fseek to get current byte offset of line
			if(fgets(line, 255, fp) == NULL)//if eof, break directly
				break;
			if(EXOR(strstr(line, search), flag.v)) {//modify for case sensitive flag
				DEB(("Debug: Byteoffset recd = %ld\n", byteoffset));
				DEB(("2Debug: Should be printing filename, f.H=%d, strcmp=%d, f.q=%d\n", flag.H, strcmp(filename, "stdin"), flag.q));
				if(flag.H && (strcmp(filename, "stdin") != 0) && (flag.q != 0))//printing filename
					printf("%s:", filename);
				if(flag.q)//quit if match + flag.q set
					return FOUND;
				if(flag.b && !flag.c)//print byteoffset if flag.b
					printf("%ld:", byteoffset);
				++count;
				if(!flag.c)//if flag.c, we need to suppress line printing. Dont bother with flag.q as already handled
					printf("%s", line);
			}
			if(flag.m && (count == flagm_arg()))//terminate program if flag.m and sufficient (nummatch) matches are found
				return FOUND;
		}
		if(flag.c && !flag.q)//print count if flag.c and not quiet mode
			printf("%d\n", count);
		fclose(fp);
		free(filename);
	}

	free(search);
	free(line);
	//fclose(patternfile);
	
	if(count > 0)
		return FOUND;

	return NOTFOUND;
}
