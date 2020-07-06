#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996)
//SW EXPERT ACADEMY 10059.유효기간
int main(void) {
	clock_t start;
	start = clock();
	FILE *fp = NULL;
	fp = fopen("sample_input.txt", "r");
	if (fp == NULL)
		printf("ERROR");
	int T;
	fscanf(fp, "%d", &T);
	char **s = malloc(sizeof(int*) *T);
	for (int i = 0; i < T; i++)
		s[i] = malloc(sizeof(int) * 4);

	for (int i = 0; i < T; i++) {
		fscanf(fp, "%s", s[i]);
	}

	for (int i = 0; i < T; i++) {
		printf("#%d ", i + 1);
		int temp = atoi(s[i]);
		int first = temp / 100;
		int second = temp - first * 100;

		//표기가 둘다되면 2 YY이면 1 둘다안되면 0
		int first_ = 0;
		int second_ = 0;

		if (first > 0) {
			if (first < 13)
				first_ = 2;
			else
				first_ = 1;
		}
		else if (first == 0) {
			first_ = 1;
		}

		if (second > 0) {
			if (second < 13)
				second_ = 2;
			else
				second_ = 1;
		}
		else if (second == 0) {
			second_ = 1;
		}
		//printf("%d %d", first_, second_);
		switch (first_) {
		case 2:
			switch (second_) {
			case 2: printf("AMBIGUOUS\n"); break;
			case 1: printf("MMYY\n"); break;
			case 0: printf("NA\n");
			}
			break;
		case 1:
			switch (second_) {
			case 2: printf("YYMM\n"); break;
			case 1:
			case 0: printf("NA\n");
			}
			break;
		case 0: printf("NA\n");
			break;
		}
	}

	for (int i = 0; i < T; i++)
		free(s[i]);
	free(s);
	clock_t end;
	end = clock();
	printf("%lf초 소요\n", (double)(end - start) / CLOCKS_PER_SEC);
	return 0;
}