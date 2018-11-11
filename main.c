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
#include "myadt.h"
#include "queue.h"

#define EXOR(a, b) (((a) && !(b)) || (!(a) && (b)))
#define MAXSEARCH 32

#define CHECKFAILURE if(flag.exit) return USAGEERR;

//return values of grep
#define FOUND 0
#define NOTFOUND 1
#define FILEERR 2
#define USAGEERR 3

int main(int argc, char *argv[]) {
	//declarations
	FILE *patternfile, *fp;
	char search[MAXSEARCH], *filename;
	int count = 0;
	long byteoffset = 0;
	queue filequeue;
	qinit(filequeue);

	//optioncheck	
	//optionprint(argc, argv);
	
	//initialize flags
	flaginit();
	//fetch options
	flagset(argc, argv);//read options
	
	CHECKFAILURE

	//printstatus
	flagstatus();

	//To open files using fopen
	//if searchfile if present, add searchfile to queue
	//If rescursive is specified, add files to queue(fifo) using appropriate code
	//if not recursive, add stdin to queue



	//make list for patternfile
	//open patternfile if present


	/*if(flag.e)//IMPLEMENT REGEX HERE
		strcpy(search, flage_arg());*/
	
	

	//SEARCH ALGORITHM:

	while(!isempty(filequeue)) {
		filename = pop(filequeue);
		if(strcmp(filename, "stdin")) 
			;//dont open but operate using stdin
		else {
			fp = fopen(filename, "r")
			if(fp == NULL)
				return FILEERR;
		}
		print file path from ./ if flag.H and isnt stdin and !flag.q
		while(!feof(fp)) {
			byteoffset = ftell(fp)//insert fseek to get current byte offset of line
			fgets();
			if(EXOR(strstr(temp, pat), flag.v)) {//modify for case sensitive flag
				if(flag.q)
					return FOUND;
				if(flag.b)
					printf("%ld", byteoffset);
				++count;
				if(!flag.c)
					printf("%s", temp);
			}
			exit if flag.m is specified AND count == nummatch
		}
		free(filename);
	}

	if(flag.c && !flag.q)
		printf("%d\n", count);


	fclose(patternfile);
	if count > 0
		return FOUND;

	return NOTFOUND;
}
