#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>

constexpr double max_d = 29999999999999992;

// char tenton();

double check(char* s0_, short* nc1_, short* nc2_, short* c1_, short* c2_, double* num1_)
{
	char tmp = '0';
	char* str = (char*)malloc(strlen(s0_));
	const char charset[] = "0123456789ABCDEFabcdef";	// available symbols
	char* endptr;

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
	
	for (int i = 0; str[i] != '\0'; ++i)
	{
		if (strchr(charset, str[i]) == NULL)
		{
			printf("[Error] Wrong input!\n%c isn`t supported!\n", str[i]);
			abort();
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

	printf("succes is %d", check(str, &nc1, &nc2, &c1, &c2, &num1));
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
