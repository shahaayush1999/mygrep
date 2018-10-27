#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>

#define EXOR(a, b) (((a) && !(b)) || (!(a) && (b)))
#define MAXSEARCH 32

typedef int returnvalue;
