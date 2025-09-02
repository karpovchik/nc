#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

constexpr double max_d = 29999999999999992;

double check(char* s_, short* nc1_, short* c1_, short* c2_, double* num1_)
{
	char* endptr;

	errno = 0;

	for (int i = 0; i < strlen(s_); ++i)		// Check for difference between the statement: "symbols in num1 < nc1";
	{
		if ((s_[i] == 'A' || s_[i] == 'B' || s_[i] == 'C' || s_[i] == 'D' || s_[i] == 'E' || s_[i] == 'F' ||
			s_[i] == 'a' || s_[i] == 'b' || s_[i] == 'c' || s_[i] == 'd' || s_[i] == 'e' || s_[i] == 'f') &&
			(nc1_ == 11 || nc1_ == 12 || nc1_ == 13 || nc1_ == 14 || nc1_ == 15))
		{
			if (nc1_ == 15 && (s_[i] == 'F' || s_[i] == 'f'))
			{
				printf("[Error] 15th numerical system doesn`t supply digit 'F' or 'f'!\n");
				abort();
			}
		}
		else if (s_[i] == '1')
		{
		
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
	if (*c1_ != 1 || *c2_ != 1)
	{
		printf("[Error] You entered a wrong symbol as a numerical system!\n");
		abort();
	}
	if (*c1_ < 2 || *c1_ > 16 || *c2_ < 2 || *c2_ > 16)
	{
		printf("[Error] This calculator supplies numerical systems from 2 to 16!\n");
		abort();
	}
	for (int i = 0; i < strlen(str_); ++i)
	{
		if (
	}
		
	return *num1_;
}
*/
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
