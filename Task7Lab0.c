#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int main()
{
	int m[SIZE] = { 0 };
	for (int i = 0; i < SIZE; ++i) {
		m[i] = rand();
	}
	for (int i = 0; i < SIZE; ++i) {
		printf("%d ", m[i]);
	}
	printf("\n");
	int max = m[0], ma = 0, min = m[0], mi = 0;
	for (int i = 1; i < SIZE; ++i) {
		if (m[i] > max) 
		{
			max = m[i];
			ma = i;
		}
		if (m[i] < min) 
		{
			min = m[i];
			mi = i;
		}
	}
	int puk = m[ma];
	m[ma] = m[mi];
	m[mi] = puk;
	for (int i = 0; i < SIZE; ++i) {
		printf("%d ", m[i]);
	}
}