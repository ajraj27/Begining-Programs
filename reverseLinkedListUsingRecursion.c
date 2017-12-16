#include<stdio.h>
#include<stdlib.h>

struct linked_list
{
	int data;
	struct linked_list* next;
};

typedef struct linked_list node;
node* head;

void Insert(int x,int n)
{
	node* temp=(node*)malloc(sizeof(node));
	temp->data=x;
	temp->next=NULL;
		
	if(n==1)
	{
		
		temp->next=head;
		head=temp;
		return ;
	}

	node* temp1=head;
	for(int i=0;i<n-2;i++)
	{
		temp1=temp1->next;
	}
		
	temp->next=temp1->next;
	temp1->next=temp;
	
}

void Reverse(node* p)
{
	if(p->next==NULL){
		head=p;
		return;
	}
	Reverse(p->next);

	node* q=p->next;
	q->next=p;
	p->next=NULL;
}

void Print()
{	
	printf("List is:");
	node* temp=head;
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

	Insert(2,1);
	Print();
	Insert(3,2);
	Print();
	Insert(4,1);
	Print();
	Insert(6,3);
	Print();
	Insert(10,3);
	Print();

	printf("\n");

	Reverse(head);
	Print();

	

	return 0;
}
	