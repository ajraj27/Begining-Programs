#include<iostream>
using namespace std;

void selectionSort(int a[],int n)
{
	int i,j;

	for(i=0;i<n-1;i++)
	{
		int iMin=i;

		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[iMin])
				iMin=j;
		}

		int temp=a[i];
		a[i]=a[iMin];
		a[iMin]=temp;
	}
}

int main()
{
	int a[]={5,4,8,3,9,6,5};
	int n=sizeof(a)/sizeof(a[0]);

	selectionSort(a,n);
	cout<< "Sorted list:";

	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";

	return 0;
}