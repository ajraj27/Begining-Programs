#include<stdio.h>

int binarySearch(int a[],int low,int high,int x)
{
	if(low>high)
		return -1;

	int mid=low+(high-low)/2;

	if(a[mid]==x)
		return mid;

	else if(a[mid]<x)
		return binarySearch(a,mid+1,high,x);

	else
		return binarySearch(a,low,mid-1,x);



}

int main()
{
	int a[]={1,3,45,65,78,89,109};
	int x;

	printf("Enter the element to search:");
	scanf("%d",&x);

	int index=binarySearch(a,0,6,x);

	if(index!=-1)
		printf("\nElement %d is at at index %d",x,index);

	else
		printf("\nElement %d not found",x);

	return 0;
}