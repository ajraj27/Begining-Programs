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

int max(int a,int b)
{
	return a>b?a:b;
}

int height(node* root)
{
	if(root==NULL)
		return 0;

	int leftTree=height(root->left);
	int rightTree=height(root->right);

	return max(leftTree,rightTree)+1;
}

int diameter(node* root)
{
	if(root==NULL)
		return 0;

	int lheight=height(root->left);
	int rheight=height(root->right);
	int ldiameter=diameter(root->left);
	int rdiameter=diameter(root->right);

	return max(lheight+rheight+1,max(ldiameter,rdiameter));
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

	printf("\n%d",diameter(root));

}