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

bool pathSum(node* root,int sum)
{
	if(root==NULL)
		return sum==0;

	if(root->left==NULL && root->right==NULL)
		return sum==root->data;

	int currSum=sum-root->data;
	if(root->left && pathSum(root->left,currSum))
		return true;

	if(root->right && pathSum(root->right,currSum))
		return true;

	return false;
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

	scanf("%d",&q);
	while(q--)
	{
		int sum;
		scanf("%d",&sum);
	pathSum(root,sum)?printf("%s\n","Yes"):printf("%s\n","No");
	}

}	