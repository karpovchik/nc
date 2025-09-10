#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>

constexpr double max_d = 29999999999999992;

// char tenton();

double check(char* s0_, short* nc1_, short* nc2_, short* c1_, short* c2_, double* num1_)
{
	int tmp = 0;
	char* str = (char*)malloc(strlen(s0_));
	const char charset[] = "0123456789ABCDEFabcdef";	// available symbols
	const char letters[] = "ABCDEFabcdef";

	for (int i = 0; s0_[i] != '\0'; ++i) { 						// remove all spacing elements
		if (!isspace(s0_[i])) { str[i] = s0_[i]; }
	}

	if (*c1_ != 1 || *c2_ != 1)									// check nces`s inputs are valid
	{
		printf("[Error] You entered a wrong symbol as a numerical system!\n");
		abort();
	}
	if (*nc1_ < 2 || *nc1_ > 16 || *nc2_ < 2 || *nc2_ > 16)		// check range of nces
	{
		printf("[Error] This calculator supplies numerical systems from 2 to 16!\n");
		abort();
	}
	
	for (int i = 0; str[i] != '\0'; ++i)						// check if every symbol is available
	{
		if (strchr(charset, str[i]) == NULL)
		{
			printf("[Error] Wrong input!\n%c isn`t supported!\n", str[i]);
			abort();
		}
	}

	for (int j = 0; str[j] != '\0'; ++j)						// check if symbols >= nc1
	{
		tmp = (int)str[j];										// take an ASCII code of a symbol
		if (strchr(letters, str[j]) != NULL)
		{
			if (*nc1_ == 15 && (tmp == 70 || tmp == 102)) {
				printf("[Error] This numeric system %d doesn`t support %c symbol!\n", *nc1_, str[j]);
				abort();
			}
			if (*nc1_ == 14 && ((tmp >= 69 || tmp <= 70) || (tmp >= 101 || tmp <= 102))) {
				printf("[Error] This numeric system %d doesn`t support %c symbol!\n", *nc1_, str[j]);
				abort();
			}
			if (*nc1_ == 13 && ((tmp >= 68 || tmp <= 70) || (tmp >= 100 || tmp <= 102))) {
				printf("[Error] This numeric system %d doesn`t support %c symbol!\n", *nc1_, str[j]);
				abort();
			}
			if (*nc1_ == 12 && ((tmp >= 67 || tmp <= 70) || (tmp >= 99 || tmp <= 102))) {
				printf("[Error] This numeric system %d doesn`t support %c symbol!\n", *nc1_, str[j]);
				abort();
			}
			if (*nc1_ == 11 && ((tmp >= 66 || tmp <= 70) || (tmp >= 98 || tmp <= 102))) {
				printf("[Error] This numeric system %d doesn`t support %c symbol!\n", *nc1_, str[j]);
				abort();
			}
			if (*nc1_ == 10 && ((tmp >= 65 || tmp <= 70) || (tmp >= 97 || tmp <= 102))) {
				printf("[Error] This numeric system %d doesn`t support %c symbol!\n", *nc1_, str[j]);
				abort();
			}
		}
		else {
			char tmp_char = str[j];
			if (atoi(&tmp_char) >= *nc1_) {
				printf("[Error] This numeric system %d doesn`t support %c symbol!\n", *nc1_, str[j]);
				abort();
			}
		}
	}

	return 0;
}

int main()
{
	char* str = (char*)malloc(18);
	short nc1 = 0, nc2 = 0;
	short c1 = 0, c2 = 0;
	double num1 = 0;

	printf("num1 > ");
	fgets(str, 18, stdin);

	printf("nc1 > ");
	c1 = scanf("%hd", &nc1);

	printf("nc2 > ");
	c2 = scanf("%hd", &nc2);

	printf("c1 %hd", c1);
	printf("c2 %hd", c2);

	check(str, &nc1, &nc2, &c1, &c2, &num1);

/*
	while (1)
	{
		if (nc1 == nc2) {
			printf("You`ve entered equal numerical systems!\n");
			break;
		}
		if (nc1 == 10) { 10toN(); }
		else {
			if (nc2 == 10) { Nto10(); }
			else { NtoM(); }
		}
	}
*/
	return 0;
}
