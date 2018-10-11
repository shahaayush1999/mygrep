///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
GREP PROBLEM STATEMENT
Implement these options:  -r  -i  -v  -f  -w  -c  -m  -b -q  -H  -h  -e patterns 
Also Need to Submit: A file with tested commands - one per linne. File named as test.txt

On Writing a test-suite
* Some projects (FILE * library, malloc and free library, etc. ) require writing a test suite. It is mentioned against those projects which require a test-suite. Typically it is required for libraries. 
* The test suite is a set of programs (written in C or Shell or C + Shell, etc). The tester runs only one program and that program in turn runs other programs. Each program tests one or more functionality of the software and reports success/failure. 
* You are supposed to write an extensive test-suite for testin your code. 
* You will also be judged on the quality of the test-suite. 


Tips to those implementing unix commands
* Useful C library functions:  getopt(for handling command line options), opendir(opening a directory),  readdir(reading a directory), stat(), chmod(), chown(),  mkdir(),  tmpnam(), tmpfile()
* Pay special attention to design of a data structure for storing the data. For example n-way tree, stack, stack of strings, array of strings, etc. 
* Pay special attention to design of how to combine various options together. Normally if you don't do this in the begining, your code will become very complex.

Projects Tasks and Submission Process

Given below is a detailed description of expectations from various projects, and the submission process: 


Submission Process:
a) create your own account on http://gitlab.com  or http://git.fosscommunity.in  (henceforth called 'server') 
b) create a private (IMP, private!) repository on the server. Give a good name to the repo
c) Create a README.md file in the repo describing your project
d) Add the user abhijit13 with permissions as 'master' to your project
d) Submit the git clone link (with the ".git" in the end) on moodle. E.g. the link looks like this:
https://gitlab.com/abhijit13/taasika.git
e) create your own pair of ssh-keys usinng ssh-keygen. Submit your own public key on server to enable write access for yourself.  
READ: 
https://docs.gitlab.com/ee/gitlab-basics/create-your-ssh-keys.html


Intermediate and continuous evaluation:
* Learn git on your own. Minimum following commands need to be learnt: 
  init, add, commit, push, pull, rm, branch, checkout
* Keep pushing your code to the server every 2-3 days. 
  Abhijit will keep 'pull'ing your code and checking the   'master' branch.
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Sample grep code picked from
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
////////////////////////////////////
