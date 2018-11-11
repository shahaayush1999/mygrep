#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <regex.h>
#include <string.h>

/*	CFLAGS FOR REGCOMP
       
       REG_EXTENDED
              Use POSIX Extended Regular Expression syntax  when  interpreting
              regex.   If  not  set,  POSIX Basic Regular Expression syntax is
              used.

       REG_ICASE
              Do not differentiate case.  Subsequent regexec() searches  using
              this pattern buffer will be case insensitive.

       REG_NOSUB
              Do  not report position of matches.  The nmatch and pmatch argu‐
              ments to regexec() are ignored if the  pattern  buffer  supplied
              was compiled with this flag set.

       REG_NEWLINE
              Match-any-character operators don't match a newline.

              A  nonmatching  list ([^...])  not containing a newline does not
              match a newline.

              Match-beginning-of-line operator (^) matches  the  empty  string
              immediately  after  a newline, regardless of whether eflags, the
              execution flags of regexec(), contains REG_NOTBOL.

              Match-end-of-line operator ($) matches the empty string  immedi‐
              ately  before  a  newline, regardless of whether eflags contains
              REG_NOTEOL.
         
     EFLAGS FOR REGEXEC
     
            REG_NOTBOL
              The match-beginning-of-line operator always fails to match (but see the compilation flag REG_NEWLINE above).
              This flag may be used when different portions of a string are passed to  regexec()
              and the beginning of the string should not be interpreted as the beginning of the line.

       REG_NOTEOL
              The match-end-of-line operator always fails to match (but see the compilation flag REG_NEWLINE above).

*/

int main(int argc, char *argv[])
{
    int a;
    int cnt = 0;
	int offset = 0;
    char str[128], substr[128];
    regex_t re;
    regmatch_t pm;
	strcpy(str, argv[1]);
	strcpy(substr, argv[2]);
    a = regcomp(&re, substr, REG_EXTENDED | REG_ICASE);
    if(a != 0)
    {
        puts("Invalid Regex");
        getchar();
        return 0;
    }

    a = regexec(&re, &str[0], 1, &pm, 0);
	while(a==0) {
		printf("\n %s match at %d", offset ? "next" : "first", offset+pm.rm_so);
		offset += pm.rm_eo;
		cnt++;
		a = regexec(&re, &str[0] + offset, 1, &pm, REG_NOTBOL);
	}
	getchar();
    return EXIT_SUCCESS;
}
