#include<stdio.h>
int a[10]={13455553,422,13,445,33,33,4,5,32,3};

int partition(int *a,int p,int r)
{
	int i=p-1,j=p,pivot=a[r],ex;
	for(j=p;j<r;j++)
	{
		if(a[j]<pivot)
		{
			i++;
			ex=a[j];
			a[j]=a[i];
			a[i]=ex;
		}

	}
	a[r]=a[++i];
	a[i]=pivot;
	return i;
}

void quicksort(int *a,int p,int r)
{
	int q;
	if (p<r)
	{
		q=partition(a,p,r);
		quicksort(a,p,q-1);
		quicksort(a,q+1,r);
	}

}

int main()
{
	int i;
	quicksort(a,0,9);
	for(i=0;i<10;i++)
		printf("%d%c",a[i],'\t');
	return 0;
}