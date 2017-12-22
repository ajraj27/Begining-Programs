#include<stdio.h>
#include<stdbool.h>

int front=-1;
int rear=-1;
int a[50];

bool isEmpty()
{
	if(front==-1 && rear==-1)
		return true;

	return false;
}

bool isFull()
{
	if((rear+1)%50==front)
		return true;

	return false;
}

void Enqueue(int x)
{
	if(isFull())
	{
		return ;
	}



	else if(isEmpty())
	{
		front=0;
		rear=0;
	}

	else
		rear=(rear+1)%50;

	a[rear]=x;

}	

void Dequeue()
{
	if(isEmpty())
		return ;

	else if(front==rear)
	{
		front=-1;
		rear=-1;
	}

	else
		front=(front+1)%50;
}

void Print()
{

	if(front==-1 && rear==-1)
	{
		printf("There's nothing to Print");
		return ;
	}
	
	printf("List is:");

	for(int i=front;i<=rear;i++)
	{
		printf(" %d",a[i]);
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