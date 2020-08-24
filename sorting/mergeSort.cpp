#include<iostream>
#include<stdlib.h>
using namespace std;

void Merge(int *a,int *L,int *R,int nL,int nR)
{
	int i=0,j=0,k=0;

	while(i<nL && j<nR)
	{
		if(L[i]<R[j])
		{
			a[k]=L[i];
			i=i+1;
		}

		else
		{
			a[k]=R[j];
			j=j+1;
		}

		k=k+1;
	}

	while(i<nL)
		a[k++]=L[i++];

	while(j<nR)
		a[k++]=R[j++];
}

void Mergesort(int *a,int n)
{

	int i;

	if(n<2)
		return ;

	int mid=n/2;

	int *L=(int*)malloc(mid*sizeof(int));
	int *R=(int*)malloc((n-mid)*sizeof(int));

	for(i=0;i<mid;i++)
		L[i]=a[i];

	for(i=mid;i<n;i++)
		R[i-mid]=a[i];

		Mergesort(L,mid);
		Mergesort(R,n-mid);
		Merge(a,L,R,mid,n-mid);

		free(L);free(R);	 
}

int main()
{
	int a[]={7,3,9,1,5,2};
	int n=sizeof(a)/sizeof(a[0]);

	Mergesort(a,n);

	for(int i=0;i<n;i++)
		cout << a[i] <<" ";

	return 0;
}