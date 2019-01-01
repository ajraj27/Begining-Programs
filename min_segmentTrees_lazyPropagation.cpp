#include<bits/stdc++.h>
using namespace std;

void build(int node,int start,int end,int tree[],int arr[]){

	if(start==end){
		tree[node]=arr[start];
		return;
	}

	int mid= (start+end)/2;
	build(2*node,start,mid,tree,arr);
	build(2*node+1,mid+1,end,tree,arr);
	tree[node]=min(tree[2*node],tree[2*node+1]);
}

void updateLazy(int node,int start,int end,int l,int r,int val,int tree[],int arr[],int lazyTree[]){

	if(start > end)
		return;

	if(lazyTree[node]!=0){
		tree[node]+=lazyTree[node];
		if(start!=end){
			lazyTree[2*node]+=lazyTree[node];
			lazyTree[2*node+1]+=lazyTree[node];
		}

		lazyTree[node]=0;
	}

	if(end < l || r < start){
		return;
	}

	if(l<=start && end<=r){
		tree[node]+=val;
		if(start!=end){
			lazyTree[2*node]+=val;
			lazyTree[2*node+1]+=val;
		}

		return ;

	}

	int mid=(start+end)/2;

		updateLazy(2*node,start,mid,l,r,val,tree,arr,lazyTree);
		updateLazy(2*node+1,mid+1,end,l,r,val,tree,arr,lazyTree);

	tree[node]=min(tree[2*node],tree[2*node+1]);
}

int queryLazy(int node,int start,int end,int l,int r,int tree[],int arr[],int lazyTree[]){

	if(start > end)
		return INT_MAX;

	if(lazyTree[node]!=0){
		tree[node]+=lazyTree[node];
		if(start!=end){
			lazyTree[2*node]+=lazyTree[node];
			lazyTree[2*node+1]+=lazyTree[node];
		}

		lazyTree[node]=0;
	}


	if(end < l || r < start){
		return INT_MAX;
	}

	if(l<=start && end<=r){
		return tree[node];
	}

	int mid=(start+end)/2;
	int p1=queryLazy(2*node,start,mid,l,r,tree,arr,lazyTree);
	int p2=queryLazy(2*node+1,mid+1,end,l,r,tree,arr,lazyTree);
	return min(p1,p2);
}

int main(){
	int n,q,a,b,num;
	char c;
	cin >> n >> q;

	int arr[n];

	for(int i=0;i<n;i++)
		cin >> arr[i];

	int tree[4*n+1];
	int lazyTree[4*n+1];

	build(1,0,n-1,tree,arr);

	for(int i=0;i<4*n;i++)
		lazyTree[i]=0;

	for(int i=0;i<q;i++){
		cin >> c >> a >> b;

		if(c=='q'){
			int ans=queryLazy(1,0,n-1,a-1,b-1,tree,arr,lazyTree);
			cout << ans <<endl;
		}

		else{
			cin >> num;
			updateLazy(1,0,n-1,a-1,b-1,num,tree,arr,lazyTree);
		}

	}

	
}