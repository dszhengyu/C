#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline(char s[], int maxline);
int trim(char s[]);
double atof(char s[]);

int main(void)
{
	int c;
	char s[MAXLINE] = {0};

	while ((c = getline(s, MAXLINE)) > 0) {
		trim(s);
		printf("%s::%f\n", s, atof(s));
	}
	
	return 0;
}







 
