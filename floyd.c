#include<stdio.h>
#include<limits.h>

void floydWarshall(int v,int a[][v+1])
{
	int i,j,k;

	for(k=1;k<=v;k++)
	{
		for(i=1;i<=v;i++)
		{
			for(j=1;j<=v;j++)
			{
				if(a[i][k]!=INT_MAX && a[k][j]!=INT_MAX && a[i][j]>a[i][k]+a[k][j])
					a[i][j]=a[i][k]+a[k][j];
			}
		}
	}
}


int main()
{
	int v,e;
	scanf("%d%d",&v,&e);

	int a[v+1][v+1];

	for(int i=1;i<=v;i++)
	{
		
		for(int j=1;j<=v;j++)
		{
			if(i==j)
				a[i][j]=0;

			else
				a[i][j]=INT_MAX;
		}
	}

	while(e--)
	{
		int start,end,val;
		scanf("%d%d%d",&start,&end,&val);

		a[start][end]=val;
	}

	floydWarshall(v,a);

	int q;
	scanf("%d",&q);
	while(q--)
	{
		int m,n;
		scanf("%d%d",&m,&n);
		printf("%d\n",a[m][n]);
	}

}