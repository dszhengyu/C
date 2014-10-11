//in case of getline(), i < strlen(s) - 2


#include <string.h>

void expand(char s[], char d[])
{
	unsigned int i, j;
	char c;

	i = j = 0;

	if (s[i] == '-') {
		d[j++] = '-';
		i++;
	}

	for (; s[i]; i++) {
		if (s[i] == '-' && (i < (strlen(s) - 2))) {
			c = s[i-1] + 1;
			while (c != s[i + 1])
				d[j++] = c++;
		}
		else
			d[j++] = s[i];//the last '\n' would be add here
	}

	d[j] = '\0';

}