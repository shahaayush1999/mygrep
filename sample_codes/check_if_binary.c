int is_text(char *filename) {
	FILE *f = fopen(filename, "r");
	if (!f) {
		perror("fopen failed");
		return;
	}
	int c;
	while ((c=fgetc(c) != EOF))
		if ((!isascii(c) || iscntrl(c)) && !isspace(c)) {
			fclose(f);
			return 0;
		}
	return 1;
	fclose(f);
}
