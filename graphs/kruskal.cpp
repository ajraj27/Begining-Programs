#include<bits/stdc++.h>
using namespace std;

struct node{
	int u,v,w;
};

int root(int i,int a[]){

	while(i!=a[i]){
		a[i]=a[a[i]];
		i=a[i];
	}

	return i;
}

int find(int u,int v,int a[]){
	int root_u=root(u,a);
	int root_v=root(v,a);

	return root_u==root_v;
}

void union_set(int u,int v,int a[],int size[]){
	int root_u=root(u,a);
	int root_v=root(v,a);

	if(root_u==root_v)
		return;

	if(size[u]<size[v]){
		a[root_u]=a[root_v];
		size[root_v]+=size[root_u];
	}

	else{
		a[root_v]=a[root_u];
		size[root_u]+=size[root_v];
	}

}

bool cmp(node a,node b){
	return a.w < b.w;
}

vector<node> kruskal(int a[],int size[],vector<node> edges,int n){
	sort(edges.begin(),edges.end(),cmp);
	vector<node> res;

	for(int i=0;i<edges.size();i++){
		if(find(edges[i].u,edges[i].v,a))
			continue;
		else{
			res.push_back(edges[i]);
			union_set(edges[i].u,edges[i].v,a,size);
		}

	}

	return res;
}

int main(){
	int n,e,u,v,w;
	cin >> n >> e;

	int a[n+1],size[n+1];

	for(int i=1;i<=n;i++){
		a[i]=i;
		size[i]=1;
	}

	vector<node> edges;

	while(e--){
		cin >> u >> v >> w;
		struct node pt={u,v,w};
		edges.push_back(pt);
	}

	vector<node> res=kruskal(a,size,edges,n);

	cout << endl;
	for(int i=0;i<res.size();i++)
		cout << res[i].u << " " << res[i].v << " " << res[i].w << endl;
}

