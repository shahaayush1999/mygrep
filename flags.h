struct flags {
	//FLAGS
	int exit;//check for critical failures. Exit in main if failure is set, using a macro
	int r;// -r search through all directories
	int i;// -i ignore upper/lower case
	int v;// -v print all non-matching lines
	int f;// -f FILE open FILE and extract 1 pattern per line to be searched
	int w;// -w lines with whole words (letters, digits and underscores NOT okay)
	int c;// -c suppress line print, only print count of matches
	int m;// -m NUM stop reading a file after NUM matches, GET MORE INFO HERE!
	int b;// -b print the 0 based byte offset before each line of output
	int q;// -q dont print anything, exit immediately even if match or error
	int H;// -H print filename before each match, default on if more than one file to be scanned
	int h;// -h dont print filename, default if only one file to be scanned
	int e;// -e PATTERN use PATTERN as pattern, GET MORE INFO HERE
	int searchfile;//check if searchfile is supplied
	int exp;//check if expression is supplied loose
	
	//FLAG ARGS
	int m_arg;
	char e_arg[30];
	char f_arg[30];
	char exp_arg[30];//search expression
	char searchfile_arg[30];//file to be searched
} flag;

void flaginit(); 
char *flagf_arg();
char *flage_arg();
int flagm_arg();
char *flagsearchfile_arg();
char *flagexp_arg();
void flagstatus();
void flagset (int argc, char *argv[]);
void optionprint(int argc, char *argv[]) ;
