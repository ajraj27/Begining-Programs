#include<stdio.h>
#include<stdbool.h>

int root(int a[],int i)
{
	while(a[i]!=i)
	{
		a[i]=a[a[i]];
		i=a[i];
	}

	return i;
}

void weighted_union(int a[],int size[],int p,int q)
{
	int root1=root(a,p);
	int root2=root(a,q);

	if(root1==root2)
		return;

	else if(size[root1]<=size[root2])
	{
		a[root1]=a[root2];
		size[root2]+=size[root1];
	}

	else
	{
		a[root2]=a[root1];
		size[root1]+=size[root2];
	}

}

bool find(int a[],int p,int q)
{
	if(root(a,p)==root(a,q))
		return true;

	return false;
}

int main()
{
	int n,num,p,q,queries;
	scanf("%d",&n);

	int a[n],size[n];

	for(int i=0;i<n;i++)
	{
		a[i]=i;
		size[i]=1;
	}

	printf("No. of subsets to do union of: ");
	scanf("%d",&num);

	while(num--)
	{
		int p,q;
		scanf("%d%d",&p,&q);
		weighted_union(a,size,p,q);

	}

	printf("No of finding queries: ");
	scanf("%d",&queries);

	while(queries--)
	{
		int m,n;
		scanf("%d%d",&m,&n);

		if(find(a,m,n))
			printf("Yes\n");

		else
			printf("No\n");
	}
}	
