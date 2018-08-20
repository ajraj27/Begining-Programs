#include<bits/stdc++.h>
using namespace std;

int minSwaps(vector<int> a,int n){
	pair<int,int> arr[n];
	int ans=0;

	for(int i=0;i<n;i++){
		arr[i]=make_pair(a[i],i);
	}

	sort(arr,arr+n);
	vector<bool> visited(n,false);

	for(int i=0;i<n;i++){
		if(visited[i] || arr[i].second==i)
			continue;

		int cycle_size=0;
		int j=i;

		while(!visited[j]){
			visited[j]=true;
			j=arr[j].second;
			cycle_size++;
		}

		ans+=cycle_size-1;

	}

	return ans;
}

void inorder(int a[],int i,int n,vector<int> &v){

	if(i>n)
		return;

	inorder(a,2*i,n,v);
	v.push_back(a[i]);
	inorder(a,2*i+1,n,v);

}

int main(){

	int n;
	cin >> n;

	int a[n];
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}

	vector<int> v;

	inorder(a,1,n,v);

	cout << minSwaps(v,n);
}