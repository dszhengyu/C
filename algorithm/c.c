#include <stdio.h>
#define ElementType int
#include "_Stack_H_by_array.h"
#include <malloc.h>


int main(void)
{
//	char *s[10] = {"6", "5", "2", "3", "+", "8", "*", "+", "3", "+", "*", "\0"};
	char *s[100];
	s[0] = "6";
	s[1] = "5";
	s[2] = "2";
	s[3] = "3";
	s[4] = "+";
	s[5] = "8";
	s[6] = "*";
	s[7] = "+";
	s[8] = "3";
	s[9] = "+";
	s[10] = "*";
	s[11] = NULL;

	printf("%d\n", postfixCalculator(s));
	return 0;
}
