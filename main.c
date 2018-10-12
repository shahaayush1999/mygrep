#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

typedef int returnvalue;

typedef struct flags {
	flag recursive = 0;// -r search through all directories
	flag ignorecase = 0;// -i ignore upper/lower case
	flag invertmatch = 0;// -v print all non-matching lines
	flag selectfile = 0;// -f FILE open this FILE and find string
	flag wholewords = 0;// -w lines with whole words (letters, digits and underscores NOT okay)
	flag countdontprint = 0;// -c suppress line print, only print count of matches
	flag nummatches = 0;// -m NUM stop reading a file after NUM matches, GET MORE INFO HERE!
	flag byteoffset = 0;// -b print the 0 based byte offset before each line of output
	flag quiet = 0;// -q dont print anything, exit immediately even if match or error
	flag withfilename = 0;// -H print filename before each match, default on if more than one file to be scanned
	flag nofilename = 0;// -h dont print filename, default if only one file to be scanned
	flag pattern = 0;// -e PATTERN use PATTERN as pattern
}


int main(int argc, char *argv[]) {
	//declarations
	
	returnvalue opt = 0;
	//fetch options
	while ((opt = getopt(argc, argv, "rivf:wcm:bqHhe:")) != -1) {
		switch (opt) {
			case 'r':
				break;
			case 'i':
				break;
			case 'v':
				break;
			case 'f':
				break;
			case 'w':
				break;
			case 'c':
				break;
			case 'm':
				break;
			case 'b':
				break;
			case 'q':
				break;
			case 'H':
				break;
			case 'i':
				break;
			case 'e':
				break;
			default: /* '?' */
				fprintf(stderr, "Check Usage in documentation\n");
				exit(EXIT_FAILURE);
		}
	}
	return 0;
}
