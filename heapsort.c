#include<stdio.h>
int a[10]={1,422,13,445,33,33,4,5,32,3};

max_heapify(int *a, int i, int n)
{
	int left = 2*i, right = 2*i+1, largest = i, temp;
	if ((left < n ) && (a[left] > a[i]))
		largest = left;
	if ((right < n) && (a[right]>a[largest]))
		largest = right;
	if (largest != i)
	{
		temp = a[i];
		a[i] = a[largest];
		a[largest] = temp;
		max_heapify(a, largest, n);
	}
}

build_maxheap(int *a, int n)
{
	int i;
	for (i = (n-1)/2; i >= 0; i--)
		max_heapify(a, i, n);
}

heapsort(int *a, int n)
{
	int i, temp;
	build_maxheap(a,n);
	for (i=n; i>0; i--)
	{
		temp = a[0];
		a[0] = a[n-1];
		a[n-1] = temp;
		n--;
		max_heapify(a,0,n);
	}
}

int main()
{
	int i;
	for (i=0; i<10; i++)
		printf("%d%c", a[i],'\t');
	heapsort(a,10);
	for (i=0; i<10; i++)
		printf("%d%c", a[i],'\t');
	return 0;
}