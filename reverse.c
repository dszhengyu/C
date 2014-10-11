#include <string.h>

//In case that getline() would introuduce '\n' in the string in the normal situation , I make j = strlen(s) - 2
void reverse(char s[])
{
	int i, j, temp;
	
	for (i = 0, j = strlen(s) - 2; i < j; i++, j--) {
		temp = s[j];
		s[j] = s[i];
		s[i] = temp;
	}
}
