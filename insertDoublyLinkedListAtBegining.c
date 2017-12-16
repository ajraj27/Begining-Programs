#include<stdio.h>
#include<stdlib.h>

struct doubly_linkedList 
{
	int data;
	struct doubly_linkedList* next;
	struct doubly_linkedList* prev;
};

typedef struct doubly_linkedList node;
node* head;

void insertAtBegining(int x)
{
	node* temp=(node*)malloc(sizeof(node));
	temp->data=x;
	temp->next=NULL;
	temp->prev=NULL;

	if(head==NULL)
	{
		head=temp;
		return;
	}

	temp->next=head;
	head->prev=temp;
	head=temp;

}

void ReversePrint()
{
	node* temp=head;
	printf("Reversed List is:");
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}

	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->prev;
	}
	printf("\n");
}
void Print()
{
	node* temp=head;
	printf("\nList is:");

	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

int main()
{

	head=NULL;

	insertAtBegining(2);Print();ReversePrint();
	insertAtBegining(4);Print();ReversePrint();
	insertAtBegining(6);Print();ReversePrint();
	insertAtBegining(8);Print();ReversePrint();
	insertAtBegining(9);Print();ReversePrint();

	return 0;
}