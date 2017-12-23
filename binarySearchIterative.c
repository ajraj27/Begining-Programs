#include<stdio.h>

int binarySearch(int a[],int n,int x)
{
	int low=0,high=n-1;
	

	while(low<=high)
	{
		int mid=low+(high-low)/2;

		if(a[mid]==x)
			return mid;

		else if(a[mid]<x)
			low=mid+1;

		else
			high=mid-1;
		
	}

	return -1;

}

int main()
{
	int a[]={1,3,45,65,78,89,109};
	int x;

	printf("Enter the element to search:");
	scanf("%d",&x);

	int index=binarySearch(a,7,x);

	if(index!=-1)
		printf("\nElement %d is at at index %d",x,index);

	else
		printf("\nElement %d not found",x);

	return 0;
}