#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h> 

#define N 100

struct Vertex{
	char label;
	bool visited;

};

int stack[N];
int top=-1;

struct Vertex* lstVertices[N];

int adjMartrix[N][N];

int vertexCount=0;

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

void depthFirstSearch()
{
	int i;

	lstVertices[0]->visited=true;

	displayVertex(0);

	push(0);

	while(!isEmpty())
	{
		int unvisitedVertex=getAdjUnvisVertex(peek());

		if(unvisitedVertex==-1)
			pop();

		else
		{
			lstVertices[unvisitedVertex]->visited=true;
			displayVertex(unvisitedVertex);
			push(unvisitedVertex);
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

   	printf("Depth First Search:");

   	depthFirstSearch();
		
      return 0;

}


