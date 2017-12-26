#include<iostream>
using namespace std;

void insertionSort(int a[],int n)
{
	for(int i=1;i<n;i++)
	{
		int value=a[i];
		int hole=i;

		while(hole>0 && a[hole-1]>value)
		{
			a[hole]=a[hole-1];
			hole=hole-1;
		}

		a[hole]=value;

	}
	
	
}

int main()
{
	int a[]={5,1,4,7,3,9};
	int n=sizeof(a)/sizeof(a[0]);

	insertionSort(a,n);

	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";	


	

	return 0;
}
