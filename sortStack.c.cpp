#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Stack
{
	int data;
	struct Stack* next;
};

typedef struct  Stack node;

void Push(node** top_ref,int x){

	node* temp=(node*)malloc(sizeof(node));

	temp->data=x;
	temp->next=*top_ref;
	*top_ref=temp;
}

void Pop(node** top_ref)
{
	node* temp=*top_ref;
	*top_ref=(*top_ref)->next;
	free(temp);
}

int Top(node* top_ref)
{
		return (top_ref)->data;
}

bool stackEmpty(node** top_ref)
{
	return *top_ref==NULL?true:false;
}

void print(node* top_ref)
{
	printf("\nSorted stack:");
	while(top_ref!=NULL)
	{
		printf("%d ",Top(top_ref));
		top_ref=top_ref->next;
	}
}

int main()
{
	printf("Enter the no. of numbers in stack:");
	int n;
	scanf("%d",&n);
	node* top=NULL,*top1=NULL;

	for(int i=0;i<n;i++)
	{
		int num;
		scanf("%d",&num);
		Push(&top,num);
	}

	while(!stackEmpty(&top))
	{
		int temp=Top(top);
		Pop(&top);

		while(!stackEmpty(&top1) && Top(top1)>temp)
		{
			Push(&top,Top(top1));
			Pop(&top1);
		}

		Push(&top1,temp);

	}

	print(top1);
}
