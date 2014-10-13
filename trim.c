#include <string.h>

int trim(char s[])
{
	int n;

	for (n = strlen(s) - 1; n >= 0; n--)
		if (s[n] != ' ' && s[n] != '\n' && s[n] != '\t')
			break;
	s[n + 1] = '\0';

	return n;
}