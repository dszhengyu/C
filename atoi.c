#include <ctype.h>

int atoi(char s[])
{
	int sum, i, sign;
	sum = i = 0;

	while (isspace(s[i]))
		++i;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '-' || s[i] == '+')
		++i;
	while (isdigit(s[i])) {
		sum = 10 * sum + (s[i] - '0');
		i++;
	}

	return sign * sum;
}