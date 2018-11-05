struct flags {
	int r;// -r search through all directories
	int i;// -i ignore upper/lower case
	int v;// -v print all non-matching lines
	int f;// -f FILE open FILE and extract 1 pattern per line to be searched
	char f_arg[30];
	int w;// -w lines with whole words (letters, digits and underscores NOT okay)
	int c;// -c suppress line print, only print count of matches
	int m;// -m NUM stop reading a file after NUM matches, GET MORE INFO HERE!
	int m_arg;
	int b;// -b print the 0 based byte offset before each line of output
	int q;// -q dont print anything, exit immediately even if match or error
	int H;// -H print filename before each match, default on if more than one file to be scanned
	int h;// -h dont print filename, default if only one file to be scanned
	int e;// -e PATTERN use PATTERN as pattern, GET MORE INFO HERE
	char e_arg[30];
	int patternfile;//check if patternfile is supplied or not
	char patternfile_arg[30];//patternfile name
	int searchfile[30];//check if searchfile is supplied
	char searchfile_arg[30];//file to be searched
	char expression[30];//search expression
} flag;

void flaginit() {
	flag.r = 0;
	flag.i = 0;
	flag.v = 0;
	flag.f = 0;//needs filename
	flag.w = 0;
	flag.c = 0;
	flag.m = 0;//needs nummatch
	flag.b = 0;
	flag.q = 0;
	flag.H = 1;
	flag.h = 0;
	flag.e = 0;//needs pattern
	flag.patternfile = 0;//needs filename
	flag.searchfile = 0;//needs filename
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
char *flagpatternfile_arg() {
	return flag.patternfile_arg;
}
char *flagsearchfile_arg() {
	return flag.searchfile_arg;
}
char *flagexpression() {
	return flag.expression;
}

void flagstatus() {
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
	printf("flag.patternfile = %d\n", flag.patternfile);
	printf("flag.searchfile = %d\n", flag.searchfile);
}

void flagset (int argc, char *argv[]) {
	int opt;
	if(argc == 1) {
		fprintf(stderr, "Check usage of MyGrep\n");
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
				printf("Filename = %s\n", flag.f_arg);
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
				printf("Nummatches = %d\n", flag.m_arg);
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
				printf("Inputstring = %s\n", flag.e_arg);
				break;
			default: /* '?' */
				fprintf(stderr, "Check Usage in documentation\n");
				exit(EXIT_FAILURE);
		}
		//printf("%c found\n", (char)opt);
	}
	if(!flag.e) {
		//check if argv[optind] doesnt exist. if true, print error
		if(optind == argc) {
			fprintf(stderr, "Pattern not entered\n");
		}
		//else feed argv in search term
		else {
			strcpy(flag.expression, argv[optind]);
		}
	}

	optind++;

	if(!flag.r) {
		//check if argv[optind] doesnt exist. if true, keep stdin as input
		if(optind == argc)
			flag.searchfile = 0;
		else {
			flag.searchfile = 1;
			strcpy(flag.searchfile_arg, argv[optind]);
		}
		// else feed argv[optind] in file to be searched
	}

	optind++;

	if(optind >= argc) {	
               fprintf(stderr, "Expected argument after options\n");
	}

}

void optionprint(int argc, char *argv[]) {
	int n;
	for(n = 0; n < argc; n++)
		printf("CMD arg %d : %s\n", n, argv[n]);
}
