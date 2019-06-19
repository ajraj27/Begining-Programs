//Height of Binary Tree.
#include<bits/stdc++.h>
using namespace std;

void correctBSTUtil(TreeNode* A,TreeNode** first,TreeNode** middle,TreeNode** last){
	if(A==NULL)
		return;

	correctBSTUtil(A->left,first,middle,last);

	if(*prev && (*prev)->val > root->val){
		if(!(*first)){
			*first=*prev;
			*middle=root;
		}

		else
			*last=root;
	}

	*prev=root;

	correctBSTUtil(A->right,first,middle,last);

}
TreeNode* correctBST(TreeNode* A){
	if(!A)
		return NULL;

	TreeNode* first=NULL,*middle=NULL.*last=NULL;
	correctBSTUtil(A,&first,&middle,&root);

	if(first && last)
		swap(first->val,last->val);
	else if(first && middle)
		swap(first->val,middle->val);
}

int main(){
	int n,k;
	cin >> n >> k;

	int a[n];

	for(int i=0;i<n;i++){
		cin >> a[i];
	}

	int ans=number(a,n,k);

	cout << ans;
}