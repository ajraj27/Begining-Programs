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

void insertAtEnd(int x)
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

	node* temp1=head;
	while(temp1->next!=NULL)
	{
		temp1=temp1->next;
	}	

	temp1->next=temp;
	temp->prev=temp1;

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

	insertAtEnd(2);Print();ReversePrint();
	insertAtEnd(4);Print();ReversePrint();
	insertAtEnd(6);Print();ReversePrint();
	insertAtEnd(8);Print();ReversePrint();
	insertAtEnd(9);Print();ReversePrint();

	return 0;
}