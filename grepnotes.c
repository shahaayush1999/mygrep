///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
GREP PROBLEM STATEMENT
Implement these options:  -r  -i  -v  -f  -w  -c  -m  -b -q  -H  -h  -e patterns 
Also Need to Submit: A file with tested commands - one per line. File named as test.txt

On Writing a test-suite
* Some projects (FILE * library, malloc and free library, etc. ) require writing a test suite. It is mentioned against those projects which require a test-suite. Typically it is required for libraries. 
* The test suite is a set of programs (written in C or Shell or C + Shell, etc). The tester runs only one program and that program in turn runs other programs. Each program tests one or more functionality of the software and reports success/failure. 
* You are supposed to write an extensive test-suite for testin your code. 
* You will also be judged on the quality of the test-suite. 

Tips to those implementing unix commands
* Useful C library functions:  getopt(for handling command line options), opendir(opening a directory),  readdir(reading a directory), stat(), chmod(), chown(),  mkdir(),  tmpnam(), tmpfile()
* Pay special attention to design of a data structure for storing the data. For example n-way tree, stack, stack of strings, array of strings, etc. 
* Pay special attention to design of how to combine various options together. Normally if you don't do this in the begining, your code will become very complex.

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Sample grep code picked from http://csourcecodes.blogspot.com/2015/03/c-program-to-simulate-grep-command-in.html

#include<stdio.h>
#include<string.h>
void main() {
	char fn[10],pat[10],temp[200];
	FILE *fp;
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
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
DETAILS OF OPTIONS IN GREP

-r, --recursive
              Read all files under each directory, recursively, following symbolic links only if they are on the command line.  Note that if no file operand  is  given,  grep  searches  the  working
              directory.  This is equivalent to the -d recurse option.

/*
-d ACTION, --directories=ACTION
              If an input file is a directory, use ACTION to process it.  By default, ACTION is read, i.e., read directories just as if they were ordinary files.  If ACTION is  skip,  silently  skip
              directories.   If  ACTION  is  recurse,  read  all files under each directory, recursively, following symbolic links only if they are on the command line.  This is equivalent to the -r
              option.
*/

-i, --ignore-case
              Ignore case distinctions in both the PATTERN and the input files.

-v, --invert-match
              Invert the sense of matching, to select non-matching lines.

-f FILE, --file=FILE
              Obtain patterns from FILE, one per line.  If this option is used multiple times or is combined with the -e (--regexp) option, search for all patterns given.  The  empty  file  contains
              zero patterns, and therefore matches nothing.

-w, --word-regexp
              Select  only  those  lines  containing  matches  that  form whole words.  The test is that the matching substring must either be at the beginning of the line, or preceded by a non-word
              constituent character.  Similarly, it must be either at the end of the line or followed by a non-word constituent character.  Word-constituent characters are letters, digits,  and  the
              underscore.

 -c, --count
              Suppress normal output; instead print a count of matching lines for each input file.  With the -v, --invert-match option (see below), count non-matching lines.

-m NUM, --max-count=NUM
              Stop reading a file after NUM matching lines.  If the input is standard input from a regular file, and NUM matching lines are output, grep ensures that the standard input is positioned
              to just after the last matching line before exiting, regardless of the presence of trailing context lines.  This enables a calling process to resume a search.  When  grep  stops  after
              NUM  matching  lines,  it outputs any trailing context lines.  When the -c or --count option is also used, grep does not output a count greater than NUM.  When the -v or --invert-match
              option is also used, grep stops after outputting NUM non-matching lines.

-b, --byte-offset
              Print the 0-based byte offset within the input file before each line of output.  If -o (--only-matching) is specified, print the offset of the matching part itself.

-q, --quiet, --silent
              Quiet; do not write anything to standard output.  Exit immediately with zero status if any match is found, even if an error was detected.  Also see the -s or --no-messages option.

-H, --with-filename
              Print the file name for each match.  This is the default when there is more than one file to search.

-h, --no-filename
              Suppress the prefixing of file names on output.  This is the default when there is only one file (or only standard input) to search.


-e PATTERN, --regexp=PATTERN
              Use  PATTERN  as  the  pattern.   If this option is used multiple times or is combined with the -f (--file) option, search for all patterns given.  This option can be used to protect a
              pattern beginning with “-”.
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
