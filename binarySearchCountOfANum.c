#include<stdio.h>
#include<stdbool.h>

int binarySearch(int a[],int n,int x, bool firstSearch)
{
	int low=0,high=n-1,result=-1;
	

	while(low<=high)
	{
		int mid=low+(high-low)/2;

		if(a[mid]==x)
		{
			result=mid;
			
			if(firstSearch)
				high=mid-1;
			else
				low=mid+1;
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
	int a[]={1,3,3,3,3,45,45,45,89,89,89,89,89,89,89,189};
	int x;

	printf("Enter the element to count:");
	scanf("%d",&x);

	int firstIndex=binarySearch(a,sizeof(a)/sizeof(a[0]),x,true);

	if(firstIndex==-1)
		printf("\nCount of %d is 0",x);

	else
	{
		int lastIndex=binarySearch(a,sizeof(a)/sizeof(a[0]),x,false);
		printf("\nCount of %d is %d",x,lastIndex-firstIndex+1);
	}


	return 0;
}