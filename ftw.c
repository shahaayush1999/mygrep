#include "ftw.h"
#include <stdlib.h>
#include <unistd.h>
#include <ftw.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int print_entry(const char *filepath, const struct stat *info, const int typeflag, struct FTW *pathinfo) {
	FILE *fp = fopen("./filequeue", "a");
	if ((strlen(filepath) > 3 && filepath[2] != '.') || strlen(filepath) <= 3)
		if (typeflag == FTW_F)  
			fprintf(fp, "%s\n", (filepath + 2));
	fclose(fp);
	return 0;
}

int print_directory_tree(const char *const dirpath) {
	int result;
	/* Invalid directory path? */
	if (dirpath == NULL || *dirpath == '\0')
		return errno = EINVAL;
	result = nftw(dirpath, print_entry, USE_FDS, FTW_PHYS);
	if (result >= 0)
		errno = result;
	return errno;
}
