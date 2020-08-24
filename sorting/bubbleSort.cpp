#include<iostream>
using namespace std;

void bubbleSort(int a[],int n)
{
	int i,j;

	for(i=0;i<n-1;i++)
	{
		int flag=0;

		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				flag=1;
			}	
		}

		if(flag==0)
			break;
	}
}

int main()
{
	int a[]={5,4,8,3,9,6,5};
	int n=sizeof(a)/sizeof(a[0]);

	bubbleSort(a,n);
	cout<< "Sorted list:";

	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";

	return 0;
}
