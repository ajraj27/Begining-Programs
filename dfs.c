#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h> 

#define N 100

int stack[N];
int top=-1;


int adjMartrix[N][N];
int visited[100]={0};

void push(int item)
{
	stack[++top]=item;
}

int  pop()
{
	return stack[top--];
}

int peek()
{
	return stack[top];
}

bool isEmpty(){
	return top==-1;
}


void addEdge(int start,int end)
{
	adjMartrix[start][end]=1;
	adjMartrix[end][start]=1;
}


int getAdjUnvisVertex(int index)
{
	int i;

	for(i=0;i<99;i++)
	{
		if(adjMartrix[index][i]==1 && visited[i]==0)
			return i;
		
	} 
         return -1;
}

void depthFirstSearch(int new)
{
	int i;

	visited[new]=1;

	printf("%d ",new);

	push(new);

	while(!isEmpty())
	{
		int unvisitedVertex=getAdjUnvisVertex(peek());

		if(unvisitedVertex==-1)
			pop();

		else
		{
			visited[unvisitedVertex]=1;
			printf("%d ",unvisitedVertex);
			push(unvisitedVertex);
		}
	}

}

int main()
{
	int i,j;

	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			adjMartrix[i][j]=0;
	}

	int v,e,start,end,new;
	scanf("%d%d",&v,&e);

	for(int i=0;i<e;i++)
	{
		scanf("%d%d",&start,&end);
		addEdge(start,end);
	}

	scanf("%d",&new);

   	depthFirstSearch(new);
		
      return 0;

}


