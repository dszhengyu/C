#include <stdio.h>

int getline(char line[], int maxline)
{
	int c, i;
	
	for(i = 0; (i < maxline) && ((c = getchar()) != EOF) && (c != '\n'); i++)
		line[i] = c;
	if (c == '\n')
		line[i++] = c;
	line[i] = '\0';
	return i;
}