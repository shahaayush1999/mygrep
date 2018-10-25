#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define EXOR(a, b) (((a) && !(b)) || (!(a) && (b)))
#define MAXSEARCH 32

typedef int returnvalue;

struct flags {
	int r;// -r search through all directories
	int i;// -i ignore upper/lower case
	int v;// -v print all non-matching lines
	int f;// -f FILE open this FILE and find string
	int w;// -w lines with whole words (letters, digits and underscores NOT okay)
	int c;// -c suppress line print, only print count of matches
	int m;// -m NUM stop reading a file after NUM matches, GET MORE INFO HERE!
	int b;// -b print the 0 based byte offset before each line of output
	int q;// -q dont print anything, exit immediately even if match or error
	int H;// -H print filename before each match, default on if more than one file to be scanned
	int h;// -h dont print filename, default if only one file to be scanned
	int e;// -e PATTERN use PATTERN as pattern, GET MORE INFO HERE
} flag;

int main(int argc, char *argv[]) {
	//declarations
	char inputstring[MAXSEARCH], search[MAXSEARCH];
	returnvalue opt = 0;
	char filename[10],temp[200];
	FILE *fp;

	flag.r = 0;
	flag.i = 0;
	flag.v = 0;
	flag.f = 0;
	flag.w = 0;
	flag.c = 0;
	flag.m = 0;
	flag.b = 0;
	flag.q = 0;
	flag.H = 0;
	flag.h = 0;
	flag.e = 0;

	//fetch options
	while ((opt = getopt(argc, argv, "rivf:wcm:bqHhe:")) != -1) {
		switch (opt) {
			case 'r'://recursive
				flag.r = 1;
				flag.H = 1;
				break;
			case 'i'://ignore case
				flag.i = 1;
				break;
			case 'v'://invert match
				flag.v = 1;
				break;
			case 'f'://filename mentioned
				flag.f = 1;
				break;
			case 'w'://whole words only
				flag.w = 1;
				break;
			case 'c'://print count not results
				flag.c = 1;
				break;
			case 'm'://stop reading file after num matches
				flag.m = 1;
				break;
			case 'b'://print byte offset
				flag.b = 1;
				break;
			case 'q'://quiet mode
				flag.q = 1;
				break;
			case 'H'://specify filename, default when multiple files
				flag.H = 1;
				flag.h = 0;
				break;
			case 'h'://dont print filename
				flag.h = 1;
				flag.H = 0;
				break;
			case 'e'://use pattern as search pattern
				flag.e = 1;
				break;
			default: /* '?' */
				fprintf(stderr, "Check Usage in documentation\n");
				exit(EXIT_FAILURE);
		}
		printf("%c found\n", (char)opt);
	}
	/*
	printf("Enter file name\n");
	scanf("%s",fn);
	printf("Enter pattern to be searched\n");
	scanf("%s",pat);
	fp=fopen(fn,"r");
	while(!feof(fp))
	{
		fgets(temp,1000,fp);
		if(strstr(temp,pat))
			printf("%s",temp);
	}
	fclose(fp);
	*/
	return 0;
}
