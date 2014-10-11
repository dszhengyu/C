#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline(char s[], int maxline);
void itoa(int n, char s[]);
void reverse(char s[]);
int atoi(char s[]);

int main(void)
{
	int c;
	char s[MAXLINE] = {0};
	char d[MAXLINE] = {0};
	
	while ((c = getline(s,MAXLINE)) > 0) {
		itoa(atoi(s), d);
		printf("%d,%s", atoi(s), d);
	}
	return 0;

}

void itoa(int n, char s[])
{
	int i, sign;

	if((sign = n) < 0)
		n = -n;
	i = 0;

	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);
	
	if (sign < 0)
		s[i++] = '-';
	s[i++] = '\n';
	s[i] = '\0';

	reverse(s);

}



