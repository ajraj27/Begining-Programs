#include<stdio.h>
#include<stdlib.h>

struct linked_list
{
	int data;
	struct linked_list* next;
};

typedef struct  linked_list node;

node* front=NULL;
node* rear=NULL;

void Enqueue(int x)
{
	node* temp=(node*)malloc(sizeof(node));
	temp->data=x;
	temp->next=NULL;

	if(front==NULL && rear==NULL)
	{
		front=temp;
		rear=temp;
		return ;
	}

	rear->next=temp;
	rear=temp;
}

void Dequeue()
{
	node* temp=front;

	if(front==NULL)
	{
		printf("No element to Dequeue");
		return ;
	}

	else if(front==rear)
	{
		front=NULL;
		rear=NULL;
	}

	else
		front=front->next;
		
		free(temp);	
}

void Print()
{
	node* temp=front;
	
	printf("List is:");
	while(temp!=NULL)
	{
		
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

int main()
{
	Enqueue(2);
	Print();
	Enqueue(4);
	Print();
	Enqueue(5);
	Print();
	Dequeue();
	Print();
	Enqueue(6);
	Print();

	return 0;
}