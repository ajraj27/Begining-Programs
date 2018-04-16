
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
	

	else if(x<(*root_ref)->data)
		insert(&((*root_ref)->left),x);

	else
		insert(&((*root_ref)->right),x);

}

int max(int a,int b)
{
    if(a>b)
        return a;
        
    return b;    
}

int height(node* root)
{
    if(root==NULL)
        return 0;
        
    int lh=height(root->left);
    int rh=height(root->right);
    
    return max(lh,rh)+1;
}

int balanced(node* root)
{
    int depth;
    if(root==NULL)
        return 1;
        
    int ldepth=height(root->left);
    int rdepth=height(root->right);
    if(ldepth>rdepth)
        depth=ldepth-rdepth;
    else
        depth=rdepth-ldepth;
    
    if(depth<=1 && balanced(root->left) && balanced(root->right))
        return 1;
        
    else    
        return 0;    
}

int main()
{	
    int t;
    scanf("%d",&t);
    
    while(t--)
    {
        node* root=NULL;
        
        int n;
        scanf("%d",&n);
        
        for(int i=0;i<n;i++)
        {
            int num;
            scanf("%d",&num);
            insert(&root,num);
        }
        
        if(n==0)
            printf("Yes\n");
            
        else{    
        
        
        if(balanced(root))
            printf("Yes\n");
        else
            printf("No\n");}
        
    }        
        
        
        
}