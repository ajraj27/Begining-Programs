#include<stdio.h>

int swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

void maxHeapify(int a[],int i,int n)
{
	int lc=2*i;
	int rc=2*i+1;

	int largest=i;

	if(lc<=n && a[lc]>a[i])
		largest=lc;

	if(rc<=n && a[rc]>a[largest])
		largest=rc;

	if(largest!=i)
	{
		swap(&a[largest],&a[i]);
		maxHeapify(a,largest,n);
	}
}

void buildHeap(int a[],int n)
{
	for(int i=n/2;i>=1;i--)
		maxHeapify(a,i,n);
}

void heapSort(int a[],int n)
{
	int heapSize=n;
	buildHeap(a,n);

	for(int i=n;i>=2;i--)
	{
		swap(&a[i],&a[1]);
		heapSize-=1;
		maxHeapify(a,1,heapSize);
	}
}

int main(){

	int n;
	scanf("%d",&n);

	int a[n+1];
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);

	heapSort(a,n);

	printf("\n");
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
}