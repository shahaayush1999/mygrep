#include "incdef.h"

int fileopen(FILE *fp, char *filename, char *mode);

int main(int argc, char *argv[]) {
	//declarations
	FILE *patternfile, *fp;
	char search[MAXSEARCH], filename[MAXSEARCH];
	int count = 0;

	//optioncheck	
	optionprint(argc, argv);
	
	//initialize flags
	flaginit();
	
	//fetch options
	flagset(argc, argv);//read options
	
	//printstatus
	flagstatus();
	optionprint(argc, argv);

	//To open files using fileopen
	//make filequeue
	//if searchfile if present, add searchfile to queue
	//If rescursive is specified, add files to queue(fifo) using appropriate code
	//if not recursive, add stdin to queue



	//make list for patternfile
	//open patternfile if present

	
	if(flag.e)//IMPLEMENT REGEX HERE
		strcpy(search, flage_arg());
	
	

	SEARCH ALGORITHM:

	while(!isempty(filequeue)) {
		if file is stdin, dont open but operate using stdin
		open file with appropriate file pointer
		if fileopen failed, return FILEERR;
		print file path if flag.H and isnt stdin and !flag.q
		while(!feof(filename)) {
			fgets();
			if(EXOR(strstr(temp, pat), flag.v)) {//modify for case sensitive flag
				return FOUND if flag.q is set
				print byte offset if required
				++count;
				if(!flag.c)
					printf("%s", temp);
			}
			exit if flag.m is specified AND count == nummatch
		}
	}

	if(flag.c && !flag.q)
		printf("%d\n", count);


	fclose(patternfile);
	if count > 0
		return FOUND;
	return NOTFOUND;
}

//fopen + err check
int fileopen(FILE *fp, char *filename, char *mode) {
	fp = fopen(flagf_arg, "r");
	if(fp == NULL) {
		fprintf(stderr, "Failed to open file\n");
		return 1;
	}
	return 0;
}
