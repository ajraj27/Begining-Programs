#include<stdio.h>

int n;


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

void increaseValue(int a[],int val)
{
	int i=n;

	if(val<a[i])
		return;

	a[n]=val;

	while(i>1 & a[i/2]<a[i])
	{
		swap(&a[i/2],&a[i]);
		i/=2;
	}
}

void insert(int a[],int val)
{
	n=n+1;
	a[n]=-1;
	increaseValue(a,val);
}
int main(){

	int val;
	scanf("%d",&n);

	int a[100];
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);

	buildHeap(a,n);

	printf("Enter the no. to insert:");
	scanf("%d",&val);

	insert(a,val);

	printf("\n");
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
}