#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h> 

#define N 100

struct Vertex{
	char label;
	bool visited;

};

int queue[N];
int top=-1;
int rear=-1,front=0,queueItemCount=0;


struct Vertex* lstVertices[N];

int adjMartrix[N][N];

int vertexCount=0;

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

void addVertex(char label)
{
	struct Vertex* temp=(struct Vertex*)malloc(sizeof(struct Vertex));
	temp->label=label;
	temp->visited=false;
	lstVertices[vertexCount++]=temp;
}

void addEdge(int start,int end)
{
	adjMartrix[start][end]=1;
	adjMartrix[end][start]=1;
}

void displayVertex(int index)
{
	printf("%c ",lstVertices[index]->label);
}

int getAdjUnvisVertex(int index)
{
	int i;

	for(i=0;i<vertexCount;i++)
	{
		if(adjMartrix[index][i]==1 && lstVertices[i]->visited==false)
			return i;
		
	} 
         return -1;
}

void breadthFirstSearch()
{
	int i,unvisitedVertex;

	lstVertices[0]->visited=true;

	displayVertex(0);

	enqueue(0);

	while(!isEmpty())
	{
		int tempVertex=dequeue();

		while((unvisitedVertex=getAdjUnvisVertex(tempVertex))!=-1)
		{

			lstVertices[unvisitedVertex]->visited=true;
			displayVertex(unvisitedVertex);
			enqueue(unvisitedVertex);
		
		}
	}	

   for(i = 0;i < vertexCount;i++) 
      lstVertices[i]->visited = false;
}

int main()
{
	int i,j;

	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			adjMartrix[i][j]=0;
	}

	   addVertex('S');  
   	addVertex('A');   
   	addVertex('B');  
   	addVertex('C');  
   	addVertex('D');


   	addEdge(0, 1);   
   	addEdge(0, 2);  
   	addEdge(0, 3);    
   	addEdge(1, 4);    
   	addEdge(2, 4);  
   	addEdge(3, 4);   

   	printf("Breadth First Search:");

   	breadthFirstSearch();
		
      return 0;

}


