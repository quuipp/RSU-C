#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void flagd(FILE* fi1, FILE* fi2)
{
	char ch;
	while ((ch = fgetc(fi1)) != EOF) {
		if (!isdigit(ch)) {
			fputc(ch, fi2);
		}
	}
}
void flagi(FILE* fi1, FILE* fi2)
{
	char ch;
	int c = 0;
	while ((ch = fgetc(fi1)) != EOF) {
		if (isalpha(ch)) {
			++c;
		}
		if (ch == '\n') {
			fputc(c + '0', fi2);
			fputc('\n', fi2);
			c = 0;
		}
	}
	fputc(c + '0', fi2);
}
void flags(FILE* fi1, FILE* fi2)
{
	char ch;
	int c = 0;
	while ((ch = fgetc(fi1)) != EOF) {
		if (!isalnum(ch) && ch != ' ') {
			++c;
		}
		if (ch == '\n') {
			fputc(c + '0', fi2);
			fputc('\n', fi2);
			c = 0;
		}
	}
	fputc(c + '0', fi2);
}
void flaga(FILE* fi1, FILE* fi2)
{
	char ch;
	while ((ch = fgetc(fi1)) != EOF) {
		if (!isdigit(ch)) {
			fprintf(fi2, "%d", ch);
		}
	}
}
int main(int argc, char* argv[])
{
	FILE* fi1 = NULL;
	FILE* fi2 = NULL;
	fopen_s(&fi1, argv[2], "r");
	char* cond = argv[1];
	if (cond[0] == '-' || cond[0] == '/') {
		if (cond[1] == 'n') {
			fopen_s(&fi2, argv[3], "w");
			switch (cond[2])
			{
			case 'd':
				flagd(fi1, fi2);
				break;
			case 'i':
				flagi(fi1, fi2);
				break;
			case 's':
				flags(fi1, fi2);
				break;
			case 'a':
				flaga(fi1, fi2);
				break;
			}
		}
		if (cond[1] != 'n' && argc <= 3) {
			fopen_s(&fi2, "out_.txt", "w");
			switch (cond[1])
			{
			case 'd':
				flagd(fi1, fi2);
				break;
			case 'i':
				flagi(fi1, fi2);
				break;
			case 's':
				flags(fi1, fi2);
				break;
			case 'a':
				flaga(fi1, fi2);
				break;
			}
		}
	}
	else {
		printf("The flag is missing");
	}
}