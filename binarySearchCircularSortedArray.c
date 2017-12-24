#include<stdio.h>

int binarySearch(int a[],int n,int x)
{
	int low=0,high=n-1;

	while(low<=high)
	{
		int mid=low+(high-low)/2;

		if(a[mid]==x)
			return mid;

		if(a[mid]<=a[high])
		{
			if(a[mid]<x && x<=a[high])
				low=mid+1;

			else
				high=mid-1;
		}

		else
		{
			if(a[mid]>x && x>=a[low])
				high=mid-1;

			else
				low=mid+1;
		}	
	}

	return -1;
}

int main()
{
	int a[]={12,15,16,17,19,5,8,9,10};
	int x;

	printf("Enter the element to search:");
	scanf("%d",&x);

	int index=binarySearch(a,sizeof(a)/sizeof(a[0]),x);

	if(index==-1)
		printf("\nElement %d not found",x);

	else
		printf("\nElement %d is at index %d",x,index);

	return 0;
}