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
	char* s1 = (char*)malloc(strlen(s0_));
	char* endptr;

	for (int i = 0; s0_[i] != '\0'; ++i) { 
		if (!isspace(s0_[i])) { s1[i] = s0_[i]; }
	}

	if (*c1_ != 1 || *c2_ != 1)
	{
		printf("[Error] You entered a wrong symbol as a numerical system!\n");
		abort();
	}
	if (*nc1_ < 2 || *nc1_ > 16 || *nc2_ < 2 || *nc2_ > 16)
	{
		printf("[Error] This calculator supplies numerical systems from 2 to 16!\n");
		abort();
	}
	
	printf("\nlength: %d", strlen(s1));
	for (int i = 0; i < s1[i] != '\0'; ++i)
	{
		if (*nc1_ <= 15 && (s1[i] == 'F' || s1[i] == 'f')) {
			printf("[Error] %dth numerical system doesn`t supply one of the symbol you entered!\n", *nc1_);
			abort();
		}	
		if (*nc1_ <= 14 && (s1[i] == 'F' || s1[i] == 'f' || s1[i] == 'E' || s1[i] == 'e')) {
			printf("[Error] %dth numerical system doesn`t supply one of the symbol you entered!\n", *nc1_);
			abort();
		}
		if (*nc1_ <= 13 && (s1[i] == 'F' || s1[i] == 'f' || s1[i] == 'E' || s1[i] == 'e' || s1[i] == 'D' || s1[i] == 'd')) {
			printf("[Error] %dth numerical system doesn`t supply one of the symbol you entered!\n", *nc1_);
			abort();
		}
		if (*nc1_ <= 12 && (s1[i] == 'F' || s1[i] == 'f' || s1[i] == 'E' || s1[i] == 'e' || s1[i] == 'D' || s1[i] == 'd' ||
			s1[i] == 'C' || s1[i] == 'c')) {
			printf("[Error] %dth numerical system doesn`t supply one of the symbol you entered!\n", *nc1_);
			abort();
		}
		if (*nc1_ <= 11 && (s1[i] == 'F' || s1[i] == 'f' || s1[i] == 'E' || s1[i] == 'e' || s1[i] == 'D' || s1[i] == 'd' || 
			s1[i] == 'C' || s1[i] == 'c' || s1[i] == 'B' || s1[i] == 'b')) {
			printf("[Error] %dth numerical system doesn`t supply one of the symbol you entered!\n", *nc1_);
			abort();
		}
		if (*nc1_ <= 10 && (s1[i] == 'F' || s1[i] == 'f' || s1[i] == 'E' || s1[i] == 'e' || s1[i] == 'D' || s1[i] == 'd' || 
			s1[i] == 'C' || s1[i] == 'c' || s1[i] == 'B' || s1[i] == 'b' || s1[i] == 'A' || s1[i] == 'a')) {
			printf("[Error] %dth numerical system doesn`t supply one of the symbol you entered!\n", *nc1_);
			abort();
		}
		tmp = s1[i];
		if (atof(&tmp) != 0.0) {
			printf("\ns1 %lf", atof(&tmp));
			if (*nc1_ <= atof(&tmp)) {
				printf("[Error] %dth numerical system doesn`t supply one of the symbol you entered!\n", *nc1_);
				abort();
			}
		}
		if (atof(&tmp) == 0.0 && (s1[i] != '0' || s1[i] != 'F' || s1[i] != 'f' || s1[i] != 'E' || s1[i] != 'e' || s1[i] != 'D' || s1[i] != 'd' || s1[i] != 'C' || 
		s1[i] != 'c' || s1[i] != 'B' || s1[i] != 'b' || s1[i] != 'A' || s1[i] != 'a')) { 
			printf("[Error] Your entered a wrong symbol: %c", tmp);
			abort();
		}
	}
/*
	*num1_ = strtod(str_, &endptr);

	if (endptr == str_)
	{
		printf("[Error] in convertion string data type to double one, you entered wrong symbols!\n");
		abort();
	}
	if (*endptr != '\0' && *endptr != str_)
	{
		printf("[Error] in convertion string data type to double one, some symbols you entered are wrong!\n");
		abort();
	}
*/		
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
