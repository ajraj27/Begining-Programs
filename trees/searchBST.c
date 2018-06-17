//Searching takes O(logn) in BST.
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct bst{

	int data;
	struct bst* left;
	struct bst* right;
};

typedef struct bst node;

void insert(node** root_ref,int x)
{

	if(*root_ref==NULL){
		node* temp=(node*)malloc(sizeof(node));
		temp->data=x;
		temp->left=NULL;
		temp->right=NULL;
		*root_ref=temp;
		 return;
		}
	

	else if(x<(*root_ref)->data)
		insert(&((*root_ref)->left),x);

	else
		insert(&((*root_ref)->right),x);

}

bool search(node** root_ref,int x)
{
	if(*root_ref==NULL)
		return false;
	else if((*root_ref)->data==x)
		return true;
	else if(x<(*root_ref)->data)
		return search(&(*root_ref)->left,x);
	else
		return search(&(*root_ref)->right,x);

}

int main()
{	
	int n,num,i,no;
	scanf("%d",&n);
	node* root=NULL;

	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		insert(&root,num);
	}

	printf("\nEnter the no. to search:");
	scanf("%d",&no);

	if(search(&root,no)==true)
		printf("\nFound");

	else
		printf("\nNot Found");




}