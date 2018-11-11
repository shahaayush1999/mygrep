void is_text(char *filename) {
	FILE *f = fopen(filename, "r");
	if (!f) {
		perror("fopen failed");
		return;
	}
	int c;
	while ((c=fgetc(c) != EOF)
		if ((!isascii(c) || iscntrl(c)) && !isspace(c)) {
			printf("is binary\n");
			fclose(f);
			return;
		}
	printf("is text\n");
	fclose(f);
}
