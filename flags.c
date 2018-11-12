#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "flags.h"

void flaginit() {
	flag.exit = 0;
	flag.r = 0;
	flag.i = 0;
	flag.v = 0;
	flag.f = 0;//needs filename
	flag.w = 0;
	flag.c = 0;
	flag.m = 0;//needs nummatch
	flag.b = 0;
	flag.q = 0;
	flag.H = 0;
	flag.h = 0;
	flag.e = 0;//needs pattern
	flag.searchfile = 0;//needs filename
	flag.exp = 0;
}

char *flagf_arg() {
	return flag.f_arg;
}
char *flage_arg() {
	return flag.e_arg;
}
int flagm_arg() {
	return flag.m_arg;
}
char *flagsearchfile_arg() {
	return flag.searchfile_arg;
}
char *flagexp_arg() {
	return flag.exp_arg;
}

void flagstatus() {
	printf("\nflag.exit = %d\n", flag.exit);
	printf("flag.r = %d\n", flag.r);
	printf("flag.i = %d\n", flag.i);
	printf("flag.v = %d\n", flag.v);
	printf("flag.f = %d\n", flag.f);
	printf("flag.w = %d\n", flag.w);
	printf("flag.c = %d\n", flag.c);
	printf("flag.m = %d\n", flag.m);
	printf("flag.b = %d\n", flag.b);
	printf("flag.q = %d\n", flag.q);
	printf("flag.H = %d\n", flag.H);
	printf("flag.h = %d\n", flag.h);
	printf("flag.e = %d\n", flag.e);
	printf("flag.exp = %d\n", flag.exp);
	printf("flag.searchfile = %d\n\n", flag.searchfile);
}

void flagset (int argc, char *argv[]) {
	int opt;
	char line[256];
	FILE *fp = fopen("patternfile.txt", "w");
	if(fp == NULL) {
		fprintf(stderr, "File IO error\n");
		flag.exit = 1;
		return;
	}

	if(argc == 1) {
		fprintf(stderr, "Usage1: grep [OPTION]... PATTERN [FILE]...\nTry 'grep --help' for more information.\n");
		flag.exit = 1;
		return;
	}

	while ((opt = getopt(argc, argv, "rivf:wcm:bqHhe:")) != -1) {
		switch (opt) {
			case 'r'://recursive
				flag.r = 1;
				if(flag.h == 0)
					flag.H = 1;
				//else dont mention filename flag.h = 1, flag.H = 0
				break;
			case 'i'://ignore case
				flag.i = 1;
				break;
			case 'v'://invert match
				flag.v = 1;
				break;
			case 'f'://filename mentioned
				flag.f = 1;
				strcpy(flag.f_arg, optarg);
				FILE *patternfile = fopen(flag.f_arg, "r");
				if(patternfile == NULL) {
					fprintf(stderr, "File IO error\n");
					flag.exit = 1;
					return;
				}
				while(fgets(line, 255, patternfile) != NULL) {
					fprintf(fp, "%s", line);
				}
				fprintf(fp, "\n");
				fclose(patternfile);
				//printf("Pattern filename = %s\n", flag.f_arg);
				break;
			case 'w'://whole words only
				flag.w = 1;
				break;
			case 'c'://print count not results
				flag.c = 1;
				break;
			case 'm'://stop reading file after num matches
				flag.m = 1;
				flag.m_arg = atoi(optarg);
				//printf("Nummatches = %d\n", flag.m_arg);
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
				strcpy(flag.e_arg, optarg);
				fprintf(fp, "%s\n", flag.e_arg);
				//printf("Inputstring = %s\n", flag.e_arg);
				break;
			default: /* '?' */
				fprintf(stderr, "Usage2: grep [OPTION]... PATTERN [FILE]...\nTry 'grep --help' for more information.\n");
				exit(EXIT_FAILURE);
		}
		//printf("%c found\n", (char)opt);
	}

	//printf("Optind = %d\n", optind);

	if(!flag.e && !flag.f) {
		//check if argv[optind] doesnt exist. if true, print error
		if(optind >= argc) {
			fprintf(stderr, "Usage3: grep [OPTION]... PATTERN [FILE]...\nTry 'grep --help' for more information.\n");
			optind--;
			flag.exit = 1;
		}
		//else feed argv in search term
		else {
			flag.exp = 1;
			strcpy(flag.exp_arg, argv[optind]);
			fprintf(fp, "%s\n", flag.exp_arg);
			//printf("Search expression = %s\n", flag.exp_arg);
		}
	}
	else
		optind--;

	optind++;

	//printf("Optind = %d\n", optind);

	if(!flag.r) {
		if(optind >= argc) {
			flag.searchfile = 0;
			printf("Searchfile not entered. Searching in stdin\n");
		}
		else {
			flag.searchfile = 1;
			strcpy(flag.searchfile_arg, argv[optind]);
			//printf("Searchfile = %s\n", flag.searchfile_arg);
		}
	}
	
	fclose(fp);

	if(flag.r && flag.searchfile) {
		flag.r = 0;
	}
	if(flag.e && flag.exp) {
		flag.exp = 0;
	}
	if(!flag.h && !flag.H && !flag.r) {
		flag.h = 1;
	}
	if(!flag.h && !flag.H && flag.r) {
		flag.H = 1;
	}
	if(optind > argc) {	
               fprintf(stderr, "Expected argument after options\n");
	}

}

void optionprint(int argc, char *argv[]) {
	int n;
	for(n = 0; n < argc; n++)
		printf("CMD arg %d : %s\n", n, argv[n]);
	printf("\n");
}
