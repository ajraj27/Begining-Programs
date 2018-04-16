#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h> 

#define N 100

int queue[N+1];
int rear=-1,front=0,queueItemCount=0;


int adjMartrix[N][N];
int distance[N]={0};

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

int getAdjUnvisVertex(int index,int new)
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

	enqueue(new);

	while(!isEmpty())
	{
		int tempVertex=dequeue();

		while((unvisitedVertex=getAdjUnvisVertex(tempVertex,new))!=-1)
		{

			distance[unvisitedVertex]=distance[tempVertex]+1;
			enqueue(unvisitedVertex);
			visited[unvisitedVertex]=1;
		
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
   
   	breadthFirstSearch(new);

   	for(i=0;i<N;i++)
   	{
   		if(distance[i]>0 || i==new)
   			printf("%d ",distance[i]);
   	}
		
      return 0;

}


