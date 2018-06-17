#include<bits/stdc++.h>
using namespace std;

struct bst
{
	int data;
	struct bst* left;
	struct bst* right;
};

typedef struct bst node;

void insert(node** root,int x){

	if(*root==NULL){
		node* temp=(node*)malloc(sizeof(node));
		temp->data=x;
		temp->left=NULL;
		temp->right=NULL;
		*root=temp;
		return;
	}

	else if(x< (*root)->data)
		insert(&((*root)->left),x);

	else
		insert(&((*root)->right),x);
}

void levelOrder(node* root){

	if(root==NULL)
		return ;

	queue< node* > q;
	q.push(root);

	  while(!q.empty()){
		node* current=q.front();
		cout << current->data << " ";

		if(current->left!=NULL)
			q.push(current->left);
		if(current->right!=NULL)
			q.push(current->right);

		q.pop();
	}
}

int main(){

	int n,num;
	cin >> n;
	node* root=NULL;

	for(int i=0;i<n;i++){
		cin >> num;
		insert(&root,num);
	}

	levelOrder(root);
}