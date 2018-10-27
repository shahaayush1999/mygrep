#include "includedefine.h"
#include "flags.h"
#include "returnval.h"

int main(int argc, char *argv[]) {
	//declarations
	FILE *fp;
	
	//initialize flags
	flaginit();
	//fetch options
	flagset(argc, argv);
	//printstatus
	flagstatus();
	
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
