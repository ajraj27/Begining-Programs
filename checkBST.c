//Insertion takes O(logn) in BST.
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

bool checkBSTutility(node* root,int min,int max)
{
	if(root==NULL)
		return true;

	if(root->data>=min && root->data<max && checkBSTutility(root->left,min,root->data) && checkBSTutility(root->right,root->data,max))
		return true;
	else
		return false;
}

bool checkBST(node* root)
{
	return checkBSTutility(root,INT_MIN,INT_MAX);
}

int main()
{	
	int n,num,i;
	scanf("%d",&n);
	node* root=NULL;

	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		insert(&root,num);
	}

	checkBST(root)?printf("\n%s","true"):printf("\n%s","false");
}