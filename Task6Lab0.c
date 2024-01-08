#include <stdio.h>
#include <ctype.h>
int cc10(int basef, char* numf) {
	char* pch = numf - 1;
	int res = 0;
	while (*++pch)
	{
		res = res * basef + ((isalpha(*pch)) ? (*pch - 'A' + 10) : (*pch - '0'));
	}
	return res;
}
int main() {
	FILE* fi1 = NULL;
	FILE* fi2 = NULL;
	fopen_s(&fi1, "1.txt", "r");
	fopen_s(&fi2, "2.txt", "w+");
	char c, c_, buf[33], * pc;
	int i = 0, smax = 48, base;
	pc = buf;
	c = fgetc(fi1);
	while (c != EOF) {
		while (c != ' ' && c != '\t' && c != '\n' && c != EOF) {
			if (isalnum(c)) {
				*pc++ = c;
			}
			c_ = c;
			c = fgetc(fi1);
		}
		if ((c == ' ' || c == '\t' || c == '\n' || c == EOF) && isalnum(c_)) {
			*pc = '\0';
			pc = buf;
			while (buf[i] != '\0') {
				++i;
				if (buf[i] > smax) {
					smax = buf[i];
				}
			}
			base = (smax > 64) ? (smax - 7 + 1 - 48) : (smax - 48 + 1);
			if (base == 1) {
				base = 10;
			}
			i = 0;
			smax = 48;
			fprintf(fi2, "For the number %s, the minimum number system is: %d\n Writing this number in decimal notation: %d\n\n", buf, base, cc10(base, buf));
		}
		c_ = c;
		c = fgetc(fi1);
	}
	fclose(fi1);
	fclose(fi2);
}