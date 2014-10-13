#include <ctype.h>

double atof(char s[])
{
	int i, sign, n;
	double sum = 0.0;
	
	for (i = 0; isspace(s[i]); )
		i++;

	if (s[i] == '-') {
		sign = -1;
		i++;
	}
	else
		sign = 1;

	for (; isdigit(s[i]); i++)
		sum = sum * 10 + (s[i] - '0');

	for ( ++i, n = 1; s[i]; i++, n *= 10)
		sum = sum * 10 + (s[i] - '0');

	return sign * sum / n;
}