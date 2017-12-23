#include<stdio.h>

int binarySearch(int a[],int n,int x)
{
	int low=0,high=n-1,result=-1;
	

	while(low<=high)
	{
		int mid=low+(high-low)/2;

		if(a[mid]==x)
		{
			result=mid;
			high=mid-1;
		}

		else if(a[mid]<x)
			low=mid+1;

		else
			high=mid-1;
		
	}

	return result;

}

int main()
{
	int a[]={1,3,45,45,45,89,189};
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