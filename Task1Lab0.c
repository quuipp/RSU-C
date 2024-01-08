#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main(int argc, char* argv[])
{
	char* cond = argv[argc - 1];
	int c2 = 0;
	if (cond[0] == '-' || cond[0] == '/') {
		if (cond[1] == 'h') {
			int a = atoi(argv[1]);
			for (int c = 2; c <= 100; ++c) {
				if (c % a == 0) {
					printf("%d\n", c);
					++c2;
				}
			}
			if (c2 == 0) {
				printf("There are no such numbers\n");
			}
		}
		if (cond[1] == 'p') {
			int a = atoi(argv[1]);
			for (int c1 = 2; c1 < a; ++c1) {
				if (a % c1 == 0) {
					printf("The number is composite\n");
					c2 = 1;
					break;
				}
			}
			if (c2 == 0)
				printf("The number is simple\n");
		}
		if (cond[1] == 's') {
			int n = atoi(_strrev(argv[1]));
			while (n > 0) {
				printf("%d ", n % 10);
				n /= 10;
			}
		}
		if (cond[1] == 'e') {
			int a = atoi(argv[1]);
			if (a > 10) {
				printf("The number must be at least 10\n");
			}
			for (int i = 1; i <= 10; ++i) {
				for (int j = 1; j <= a; ++j) {
					printf("%.0f\n", pow(i, j));
				}
			}
		}
		if (cond[1] == 'a') {
			int a = atoi(argv[1]);
			for (int i = 1; i <= a; ++i) {
				c2 += i;
			}
			printf("%d\n", c2);
		}
		if (cond[1] == 'f') {
			int a = atoi(argv[1]);
			c2 = 1;
			for (int i = 1; i <= a; ++i) {
				c2 *= i;
			}
			printf("%d\n", c2);
		}
	}
	else {
		printf("The flag is missing");
	}
}