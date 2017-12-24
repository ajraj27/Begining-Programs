#include<stdio.h>

int binarySearch(int a[],int n){

	int low=0,high=n-1;

	while(low<=high)
	{

		int mid=low+(high-low)/2;
		int next=(mid+1)%n;
		int prev=(mid+n-1)%n;

		if(a[low]<=a[high])
			return low;

		else if(a[mid]<=a[next] && a[mid]<=a[prev])
			return mid;

		else if(a[mid]<=a[high])
			high=mid-1;

		else
			low=mid+1;
	}

	return -1;
}



int main()
{
	int a[]={45,56,67,2,3,5,9,10};

	int  count=binarySearch(a,sizeof(a)/sizeof(a[0]));
	
	if(count ==-1)
		printf("Unexpexted Answer");

	else
		printf("This array is rotated %d times",count);

	return 0;
}