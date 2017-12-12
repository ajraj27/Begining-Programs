#include<stdio.h> 
#include<stdlib.h>

struct linked_list 
{
	int data;
	struct linked_list* next;
};

typedef struct linked_list node;
node* head;
int flag=0;

void Insert(int x)
{
	node* temp=(node*)malloc(sizeof(node));	
	

	

	if(flag==0)
	{
		temp->data=x;
		temp->next=head;
		head=temp;
		flag=1;
		return ;
	}
	

	node* temp1=head;
	while(temp1->next!=NULL)
	{
		temp1=temp1->next;
	}
		
	temp1->next=temp;
	temp->data=x;
	temp->next=NULL;
		
	
}

void print()
{
	node* temp=head;
	
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
	head=NULL;
	int i,x,n;
	
	printf("How mmany intergers to enter?");
	scanf("%d",&n);

	for(i=0;i<n;i++){
		
		printf("Enter the interger:");
		scanf("%d",&x);
		Insert(x);
		print();
	}

	return 0;
}
	
