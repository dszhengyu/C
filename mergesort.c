#include<stdio.h>
int a[10]={1332,212,23,45,2,3,142,324,12232,566};
int A[10],B[10];

void merge(int *a,int p,int q,int r)
{
	int i=0,j=0,k=p;
	for(i=p;i<q;i++)
		A[j++]=a[i];
	A[j]='\0';
	j=0;
	for(i=q;i<r;i++)
		B[j++]=a[i];
	B[j]='\0';
	i=0;
	j=0;
	while(A[i]&&B[j])
	{
		if(A[i]>B[j])
			a[k++]=B[j++];
		else 
			a[k++]=A[i++];
	}
	while(A[i])
		a[k++]=A[i++];
	while(B[j])
		a[k++]=B[j++];

}

void mergesort(int *a,int p,int r)
{
	if (p<r)
	{
		int q=(p+r-1)/2;
		mergesort(a,p,q);

		mergesort(a,q,r);	
	
		merge(a,p,q,r);
	}
}


int main()
{
	int i;
	for(i=0;i<10;i++)
		printf("%d%c",a[i],'\t');
	mergesort(a,0,10);
	for(i=0;i<10;i++)
		printf("%d%c",a[i],'\t');
	return 0;
}