#include<stdio.h>
int a[20] = {1,2,1,2,3,4,5,3,6,7,4,3,1,5,4,6,7,14,13,12};
int b[15];
int c[20];

void countingsort(int *a, int *b, int *c, int n, int m)
{
	int i;
	for (i=0; i<n; i++)
		b[a[i]]++;
	for (i=1; i<m; i++)
		b[i] = b[i] + b[i-1];
	for (i=0; i<n; i++)
	{
		c[b[a[i]]] = a[i];
		b[a[i]]--;
	}
}
