#include<bits/stdc++.h>
using namespace std;

#define N 10005
int a[N],siz[N];

int root(int i){
	while(i!=a[i]){
		a[i]=a[a[i]];
		i=a[i];
	}

	return i;
}

int find(int u,int v){
	int root_a=root(u);
	int root_b=root(v);

	return root_a==root_b;
}

void union_set(int u,int v){
	int root_a=root(u);
	int root_b=root(v);

	if(root_a==root_b)
		return;

	if(siz[root_a]>siz[root_b]){
		a[root_b]=a[root_a];
		siz[root_a]+=siz[root_b];
	}

	else{
		a[root_a]=a[root_b];
		siz[root_b]+=siz[root_a];
	}

}

int main(){
	int n,num;
	cin >> n;

	for(int i=1;i<=n;i++){
		a[i]=i;
		siz[i]=1;
	}

	for(int i=1;i<=n;i++){
		cin >> num;
		union_set(i,num);
	}

	int ctr=0;

	for(int i=1;i<=n;i++){
		if(a[i]==i)
			ctr++;
	}

	cout << ctr;

}