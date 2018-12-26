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

void update(int node,int start,int end,int idx,int val,int tree[],int arr[]){

	if(start==end){
		arr[idx]=val;
		tree[node]=val;
		return;
	}

	int mid=(start+end)/2;

	if(start<=idx && idx<=mid)
		update(2*node,start,mid,idx,val,tree,arr);
	else
		update(2*node+1,mid+1,end,idx,val,tree,arr);

	tree[node]=min(tree[2*node],tree[2*node+1]);
}

int query(int node,int start,int end,int l,int r,int tree[],int arr[]){

	if(end < l || r < start){
		return INT_MAX;
	}

	if(l<=start && end<=r){
		return tree[node];
	}

	int mid=(start+end)/2;
	int p1=query(2*node,start,mid,l,r,tree,arr);
	int p2=query(2*node+1,mid+1,end,l,r,tree,arr);
	return min(p1,p2);
}

int main(){
	int n,q,a,b;
	char c;
	cin >> n >> q;

	int arr[n];

	for(int i=0;i<n;i++)
		cin >> arr[i];

	int tree[4*n+1];

	build(1,0,n-1,tree,arr);

	for(int i=0;i<q;i++){
		cin >> c >> a >> b;

		if(c=='q'){
			int ans=query(1,0,n-1,a-1,b-1,tree,arr);
			cout << ans <<endl;
		}

		else
			update(1,0,n-1,a-1,b,tree,arr);

	}

	
}