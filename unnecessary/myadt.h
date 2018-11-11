//defined below is modified source code of strcmp to match my datatype
int stringcmp(const char *p1, const char *p2)
{
	const unsigned char *s1 = (const unsigned char *) p1;
	const unsigned char *s2 = (const unsigned char *) p2;
	unsigned char c1, c2;
	do {
		c1 = (unsigned char) *s1++;
		c2 = (unsigned char) *s2++;
		if (c1 == '\0')
			return c1 - c2;
	}
	while (c1 == c2);
	return c1 - c2;
}

char switchcaseofchar(char c) {
	if(c >= 65 && c <= 90)
		c += 32;
	else if(c >= 97 && c <= 122)
		c -= 32;
	return c;
}

//defined below is modified source code of strstr to match my datatype
char *stringstring(register char *string, char *substring, int insensitive) {
	register char *a, *b;
	register char x, y;
	/* First scan quickly through the two strings looking for a
	 * single-character match.  When it's found, then compare the
	 * rest of the substring.
	 */
	b = substring;
	if (*b == 0) {
		return string;
	}
	if(!insensitive) {
		for ( ; *string != 0; string += 1) {
			if (*string != *b) {
				continue;
			}
			a = string;
			while (1) {
				if (*b == 0) {
					return string;
				}
				if (*a++ != *b++) {
					break;
				}
			}
			b = substring;
		}
	}
	else { //if(insentitive = 1)
		for ( ; *string != 0; string += 1) {
			x = (*string != *b);
			y = (*string != switchcaseofchar(*b));
			if (x && y) {//Additional step to prevent shortcircuit of condition
				continue;
			}
			a = string;
			while (1) {
				if (*b == 0) {
					return string;
				}
				x = (*a != *b);
				y = (*a != switchcaseofchar(*b));
				(a++);
				(b++);
				if (x && y) {
					break;
				}
			}
			b = substring;
		}
	}
	return (char *) 0;
}

