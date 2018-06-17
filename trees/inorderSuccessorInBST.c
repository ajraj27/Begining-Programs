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

node* search(node* root,int x)
{
	if(x<root->data)
		return search(root->left,x);
	if (x>root->data)
		return search(root->right,x);
	return root;
}

void getSuccessor(node* root,int x)
{


	node* current=search(root,x);

	if(current==NULL)
		return;

	if(current->right!=NULL)
	{
		node* temp=current->right;
		while(temp->left!=NULL)
			temp=temp->left;

		printf("%d",temp->data);	
	}

	else{
		node* succesor=NULL,*ancestor=root;
		while(current!=ancestor){
		if(x<ancestor->data)
		{
			succesor=ancestor;
			ancestor=ancestor->left;
		}

		else
			ancestor=ancestor->right;
	}

		succesor!=NULL?printf("%d",succesor->data):printf("No successor");

	}
}

int main()
{	
	int n,num,i,number;
	scanf("%d",&n);
	node* root=NULL;

	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		insert(&root,num);
	}

	printf("\nEnter the no. to find its inorder successor:");
	scanf("%d",&number);


	getSuccessor(root,number);

}
