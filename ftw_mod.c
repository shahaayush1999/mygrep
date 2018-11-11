#define _XOPEN_SOURCE 700

#define _LARGEFILE64_SOURCE
#define _FILE_OFFSET_BITS 64 
#include <stdlib.h>
#include <unistd.h>
#include <ftw.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>



#ifndef USE_FDS
#define USE_FDS 15
#endif

int print_entry(const char *filepath, const struct stat *info, const int typeflag, struct FTW *pathinfo) {
	if ((strlen(filepath) > 3 && filepath[2] != '.') || strlen(filepath) <= 3) {
		if (typeflag == FTW_F) 
			printf(" %s\n", filepath);
//		else if (typeflag == FTW_D || typeflag == FTW_DP)
//			printf(" %s/\n", filepath);
		return 0;
	}
}
int print_directory_tree(const char *const dirpath)
{
	int result;
	/* Invalid directory path? */
	if (dirpath == NULL || *dirpath == '\0')
		return errno = EINVAL;
	result = nftw(dirpath, print_entry, USE_FDS, FTW_PHYS);
	if (result >= 0)
		errno = result;
	return errno;
}

int main(int argc, char *argv[])
{
	int arg;
	if (argc < 2) {
		if (print_directory_tree(".")) {
			fprintf(stderr, "%s.\n", strerror(errno));
			return EXIT_FAILURE;
		}

	} else {
		for (arg = 1; arg < argc; arg++) {
			if (print_directory_tree(argv[arg])) {
				fprintf(stderr, "%s.\n", strerror(errno));
				return EXIT_FAILURE;
			}

		}

	}
	return EXIT_SUCCESS;
}
