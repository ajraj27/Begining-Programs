#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h> 

#define N 100

int stack[N];
int top=-1;
int ctr=0;



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


void addEdge(int v,int adjMatrix[][v],int start,int end)
{
	adjMatrix[start][end]=1;
	adjMatrix[end][start]=1;
}


int getAdjUnvisVertex(int visited[],int index,int v,int adjMatrix[][v])
{
	int i;

	for(i=1;i<=v;i++)
	{
		if(adjMatrix[index][i]==1 && visited[i]==0)
			return i;
		
	} 
         return -1;
}

void depthFirstSearch(int v,int new,int visited[],int adjMatrix[][v])
{
	int i;
	
	visited[new]=1;

	push(new);

	while(!isEmpty())
	{
		int unvisitedVertex=getAdjUnvisVertex(visited,peek(),v,adjMatrix);

		if(unvisitedVertex==-1)
			pop();

		else
		{
			visited[unvisitedVertex]=1;
			push(unvisitedVertex);
		}
	}

	ctr++;

}

int main()
{
	int i,j;

	

	int v,e,start,end,new;
	scanf("%d%d",&v,&e);

	int adjMatrix[v+1][v+1];
	int visited[v+1];

	for(int i=1;i<=v;i++)
		visited[i]=0;

	for(i=1;i<=v;i++)
	{
		for(j=1;j<=v;j++)
			adjMatrix[i][j]=0;
	}


	for(int i=0;i<e;i++)
	{
		scanf("%d%d",&start,&end);
		addEdge(v,adjMatrix,start,end);
	}

	for(int i=1;i<=v;i++)
	{
		if(visited[i]==0)
   			depthFirstSearch(v,i,visited,adjMatrix);
   	}	

   	printf("%d",ctr);
		
      return 0;

}


