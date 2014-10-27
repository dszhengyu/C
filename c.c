#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline(char s[], int maxline);
void itoa_re(int n, char s[]);
int trim(char s[]);
void reverse(char s[]);
int atoi(char s[]);


int main(void)
{
	int c;
	char s[MAXLINE] = {0};
	char d[MAXLINE] = {0};

	while ((c = getline(s, MAXLINE)) > 0) {
		trim(s);
		d[0] = '\0';
		c = atoi(s);
		itoa_re(c, d);
		printf("%s\n", d);
	}
	
	return 0;
}








 
