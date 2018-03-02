//Insertion takes O(logn) in BST.
#include<stdio.h>
#include<stdlib.h>

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

node* minRight(node* root)
{
	if(root->left==NULL)
		return root;

	 return minRight(root->left);

}

void deleteANode(node** root,int x)
{
	if(*root==NULL)
		return;
	if(x<(*root)->data)
		return deleteANode(&((*root)->left),x);
	if(x>(*root)->data)
		return deleteANode(&((*root)->right),x);
	else
	{
		if((*root)->left==NULL && (*root)->right==NULL)
		{
			free(*root);
			*root=NULL;
			return;
		}

		else if((*root)->left==NULL)
		{
			node* temp=*root;
			(*root)=(*root)->right;
			free(temp);
			return;
		}

		else if((*root)->right==NULL)
		{
			node* temp=*root;
			(*root)=(*root)->left;
			free(temp);
			return;
		}

		else{
			node* temp=minRight((*root)->right);
			(*root)->data=temp->data;
			deleteANode(&((*root)->right),temp->data);
			return;
		}
	}
}

void preorderTraversal(node* root)
{
	if(root==NULL)
		return;

	printf("%d ",root->data);
	preorderTraversal(root->left);
	preorderTraversal(root->right);

}

int main()
{	
	int n,num,i,delNum;
	scanf("%d",&n);
	node* root=NULL;

	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		insert(&root,num);
	}

	printf("Enter a no. to delete:" );
	scanf("%d",&delNum);

	deleteANode(&root,delNum);

	printf("\n");
	printf("Preorder Traversal:");
	preorderTraversal(root);

}
