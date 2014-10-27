#include <string.h>

void reverse(char s[])
{
	int i, j, temp;
	
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		temp = s[j];
		s[j] = s[i];
		s[i] = temp;
	}
}

void reverse_re(char s[], int i, int j)
{
	if (i >= j)
		return;
	else {
		char c;
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		reverse_re(s, ++i, --j);
	}
}