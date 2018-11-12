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
struct FTW;
int print_entry(const char *filepath, const struct stat *info, const int typeflag, struct FTW *pathinfo);
int print_directory_tree(const char *const dirpath);
