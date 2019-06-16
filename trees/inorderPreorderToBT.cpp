
#include<bits/stdc++.h>
using namespace std;

struct bst{

	int data;
	struct bst* left;
	struct bst* right;
};

typedef struct bst node;

int search(int inorder[],int data,int start,int end){

	for(int i=start;i<=end;i++){
		if(inorder[i]==data)
			return i;
	}

}

node* constructBT(int inorder[],int preorder[],int start,int end,int* index){

	if(start>end)
		return NULL;

	node* newNode=(node*)malloc(sizeof(node));
	newNode->data=preorder[*index];
	newNode->left=NULL;
	newNode->right=NULL;
	*index=*index+1;

	if(start==end)
		return newNode;

	int inIndex=search(inorder,newNode->data,start,end);
	newNode->left=constructBT(inorder,preorder,start,inIndex-1,index);
	newNode->right=constructBT(inorder,preorder,inIndex+1,end,index);
	return newNode;
	
}

void print(node* root){

	if(root==NULL)
		return;

	print(root->left);
	cout << root->data<<endl;
	print(root->right);
}

int main()
{	
	int n,num,i;
	scanf("%d",&n);

	int inorder[n],preorder[n];

	for(i=0;i<n;i++)
		cin >> inorder[i];

	for(int i=0;i<n;i++)
		cin >> preorder[i];
		
	int index=0;
	node* temp=constructBT(inorder,preorder,0,n-1,&index);

	print(temp);


}