#include<stdio.h>
#include<stdlib.h>

struct tree{

	int data;
	struct tree* left;
	struct tree* right;
};

typedef struct tree node;

node* newNode(int x)
{
	node* temp=(node*)malloc(sizeof(node));
	temp->data=x;
	temp->left=NULL;
	temp->right=NULL;

	return temp;
}

void getParent(node* root,int parent,node** temp)
{
	if(root==NULL)
		return;
	if(root->data==parent)
	{
		*temp=root;
	}
	getParent(root->left,parent,temp);
	getParent(root->right,parent,temp);
}

void getNode(node* root,int parent,int child,char ch)
{
	node* temp=NULL;

	getParent(root,parent,&temp);

	if(ch=='L')
		temp->left=newNode(child);
	else
		temp->right=newNode(child);
}

int findMirrorRec(int target,node* left,node* right)
{
	if(left==NULL || right==NULL)
		return 0;

	if(left->data==target)
		return right->data;
	if(right->data==target)
		return left->data;

	int mirror=findMirrorRec(target,left->left,right->right);

	if(mirror)
		return mirror;

	findMirrorRec(target,left->right,right->left);
}

int findMirror(node* root,int target)
{
	if(root==NULL)
		return 0;

	if(root->data==target)
		return target;

	return findMirrorRec(target,root->left,root->right);
}

int main()
{
	int n,q,parent,child,target;
	char ch;
	scanf("%d%d",&n,&q);

	node* root=newNode(1);
	n=n-1;

	while(n--){

		scanf("%d%d",&parent,&child);
		scanf("\n%c",&ch);

		getNode(root,parent,child,ch);
	}

	while(q--)
	{
		scanf("%d",&target);

		int mirror=findMirror(root,target);

		if(mirror)
			printf("%d\n",mirror);

		else
			printf("-1\n");
	}

}