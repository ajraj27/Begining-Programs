//Insertion takes O(logn) in BST.
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
	

	else if(x<=(*root_ref)->data)
		insert(&((*root_ref)->left),x);

	else
		insert(&((*root_ref)->right),x);

}

void preorderTraversal(node* root)
{
	if(root==NULL)
		return;

	printf("%d ",root->data);
	preorderTraversal(root->left);
	preorderTraversal(root->right);

}

void inorderTraversal(node* root)
{
	if(root==NULL)
		return ;

	inorderTraversal(root->left);
	printf("%d ",root->data);
	inorderTraversal(root->right);
}

void postorderTraversal(node* root)
{
	if(root==NULL)
		return;

	postorderTraversal(root->left);
	postorderTraversal(root->right);
	printf("%d ",root->data);

}

void invertTree(node** root)
{
	if(*root==NULL)
		return;

	node* temp;

	invertTree(&((*root)->left));
	invertTree(&((*root)->right));

	temp=(*root)->left;
	(*root)->left=(*root)->right;
	(*root)->right=temp;
}


int main()
{	
	int n,num,i,q;
	scanf("%d",&n);
	node* root=NULL;

	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		insert(&root,num);
	}

	invertTree(&root);

	inorderTraversal(root);

	printf("\n");

	preorderTraversal(root);

	printf("\n");
	postorderTraversal(root);



}	