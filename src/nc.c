#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>

constexpr double max_d = 29999999999999992;

double check(char* s0_, short* nc1_, short* c1_, short* c2_, double* num1_)
{
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

	for (int i = 0; i < s1[i] != '\0'; ++i)
	{
		if (*nc1_ <= 15 && (s1[i] == 'F' || s1[i] == 'f')) {
			printf("[Error] %dth numerical system doesn`t supply one of the symbol you entered!\n", *nc1_);
			abort();
		}	
		if (*nc1_ <= 14 && s1[i] == 'F' || s1[i] == 'f' || s1[i] == 'E' || s1[i] == 'e') {
			printf("[Error] %dth numerical system doesn`t supply one of the symbol you entered!\n", *nc1_);
			abort();
		}
		if (*nc1_ <= 13 && s1[i] == 'F' || s1[i] == 'f' || s1[i] == 'E' || s1[i] == 'e' || s1[i] == 'D' || s1[i] == 'd') {
			printf("[Error] %dth numerical system doesn`t supply one of the symbol you entered!\n", *nc1_);
			abort();
		}
		if (*nc1_ <= 12 && s1[i] == 'F' || s1[i] == 'f' || s1[i] == 'E' || s1[i] == 'e' || s1[i] == 'D' || s1[i] == 'd' ||
			s1[i] == 'C' || s1[i] == 'c') {
			printf("[Error] %dth numerical system doesn`t supply one of the symbol you entered!\n", *nc1_);
			abort();
		}
		if (*nc1_ <= 11 && s1[i] == 'F' || s1[i] == 'f' || s1[i] == 'E' || s1[i] == 'e' || s1[i] == 'D' || s1[i] == 'd' || 
			s1[i] == 'C' || s1[i] == 'c' || s1[i] == 'B' || s1[i] == 'b') {
			printf("[Error] %dth numerical system doesn`t supply one of the symbol you entered!\n", *nc1_);
			abort();
		}
		if (*nc1_ <= 10 && s1[i] == 'F' || s1[i] == 'f' || s1[i] == 'E' || s1[i] == 'e' || s1[i] == 'D' || s1[i] == 'd' || 
			s1[i] == 'C' || s1[i] == 'c' || s1[i] == 'B' || s1[i] == 'b' || s1[i] == 'A' || s1[i] == 'a') {
			printf("[Error] %dth numerical system doesn`t supply one of the symbol you entered!\n", *nc1_);
			abort();
		}
		if (atoi(s[i]) != 0) {
			if (*nc1_ <= s[i]) {
				printf("[Error] %dth numerical system doesn`t supply one of the symbol you entered!\n", *nc1_);
				abort();
			}
		}
	}

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
		
	return *num1_;
}

int main()
{
	ssize_t buf = 18;
	char str [buf];
	short nc1 = 0, nc2 = 0;
	short c1 = 0, c2 = 0;
	double num1 = 0;

	printf("num1 > ");
	fgets(str, buf, stdin);

	printf("nc1 > ");
	scanf("%d", &nc1);

	printf("nc2 > ");
	scanf("%d", &nc2);

//	check(str, &nc1, &nc2, &c1, &c2, &num1);
	char* end;
	num1 = strtod(str, &end);
	printf("%lf", num1);

	return 0;
}
