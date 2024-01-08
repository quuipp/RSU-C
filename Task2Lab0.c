#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int main(int argc, char* argv[])
{
	char* cond = argv[argc - 1];
	int c2 = 0;
	if (cond[0] == '-' || cond[0] == '/') {
		if (cond[1] == 'q') {
			float a = atoi(argv[1]);
			float b = atoi(argv[2]);
			float c = atoi(argv[3]);
			while (1) {
				if (a == 0) {
					printf("solution %f\n", -c / b);
					break;
				}
				float D = (b * b) - (4 * a * c);
				if (D < 0) {
					printf("there is no solution\n");
					break;
				}
				else if (D == 0) {
					printf("solution %f\n", -b / (2 * a));
					break;
				}
				else {
					float x1 = (-b + sqrt(D)) / (2 * a);
					float x2 = (-b - sqrt(D)) / (2 * a);
					printf("x1 = %f x2 = %f\n", x1, x2);
					break;
				}
			}
		}
		if (cond[1] == 'm') {
			int a = atoi(argv[1]);
			int b = atoi(argv[2]);
			if (a % b == 0)
				printf("yes\n");
			else
				printf("no\n");
		}
		if (cond[1] == 't') {
			int a = atoi(argv[1]);
			int b = atoi(argv[2]);
			int c = atoi(argv[3]);
			if (a * a + b * b == c * c)
				printf("yes");
			else
				printf("no");
		}
	}
	else {
		printf("The flag is missing");
	}
}