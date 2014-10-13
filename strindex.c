//reverse : from tail to front

#include <string.h>

int strindex(char s[], char p[])
{
	int i, j, k;
	
	for (i = strlen(s) - 1; i >= 0; i--) {
		for (j = i, k = 0; p[k] && s[j] == p[k]; j++, k++)
			;
		if (k > 0 && p[k] == '\0')
			return i;
	}

	return -1;				
}