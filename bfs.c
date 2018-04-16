#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h> 

#define N 100

int queue[N];
int top=-1;
int rear=-1,front=0,queueItemCount=0;


int adjMartrix[N][N];

int vertexCount=0;
int visited[100]={0};

void enqueue(int item)
{
	queue[++rear]=item;
	queueItemCount++;
}

int  dequeue()
{
	queueItemCount--;
	return queue[front++];
}


bool isEmpty(){
	return queueItemCount==0;
}



void addEdge(int start,int end)
{
	adjMartrix[start][end]=1;
	adjMartrix[end][start]=1;
}


int getAdjUnvisVertex(int index)
{
	int i;

	for(i=0;i<100;i++)
	{
		if(adjMartrix[index][i]==1 && visited[i]==0)
			return i;
		
	} 
         return -1;
}

void breadthFirstSearch(int new)
{
	int i,unvisitedVertex;

	visited[new]=1;

	printf("%d ",new);

	enqueue(new);

	while(!isEmpty())
	{
		int tempVertex=dequeue();

		while((unvisitedVertex=getAdjUnvisVertex(tempVertex))!=-1)
		{

			visited[unvisitedVertex]=1;
			printf("%d ",unvisitedVertex);
			enqueue(unvisitedVertex);
		
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
		if(i==0)
			new=start;
		addEdge(start,end);
	}
   

   	breadthFirstSearch(new);
		
      return 0;

}


