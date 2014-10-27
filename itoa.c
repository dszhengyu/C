#include <string.h>

void reverse(char s[]);

void itoa(int n, char s[])
{
	int i = 0;

	do {
		s[i] = n % 10 + '0';
		i++;
	} while (n /= 10);

	s[i] = '\0';

	reverse(s);


}

//!!!remenber to initial the s[] every time you use the funtion agian!!!
void itoa_re(int n, char s[])
{
	if (!n)
		;
	else {
		int cnt;
		int n_ = n / 10;
		itoa_re(n_, s);
		cnt = strlen(s);
		s[cnt] = n % 10 + '0';
		s[++cnt] = '\0';
	}
}

