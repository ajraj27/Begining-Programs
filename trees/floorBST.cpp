//Searching takes O(logn) in BST.
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

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

node* Floor(node* root,node** prev,int k){
	if(root==NULL)
		return NULL;

	node* left=Floor(root->left,prev,k);

	if(left)
		return left;

	if(root->data==k)
		return root;

	if(root->data>k)
		return *prev;

	*prev=root;

	return Floor(root->right,prev,k);

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

	node* s=NULL;

	//ksmallest(root,&s,6);

	printf("%d",Floor(root,&s,7)->data);

	



}