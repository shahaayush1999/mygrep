#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readline(FILE *f, char *buffer, size_t len) {
	char c; 
	int i;
	memset(buffer, 0, len);
	for (i = 0; i < len; i++) {
		c = fgetc(f);
		if (!feof(f)) {
			if (c == '\n')	{
				buffer[i] = '\0';
				return i;
			}
			else
				buffer[i] = c;
		}
		else
			return -1;
	}

	return -1; 
}

int main() {
	FILE *fp = fopen("main.c", "r");
	char line[128];
	while(readline(fp, line, 128) > 0)
		printf("%s", line);
	return 0;
}

