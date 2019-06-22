
#include<bits/stdc++.h>
using namespace std;

vector<int> shortestDistance(int src,int n,vector<int> list[]){
	vector<int> dist(n,-1);
	dist[src]=0;
	queue<int> q;
	q.push(src);

	while(!q.empty()){
		int v=q.front();
		q.pop();

		for(int i=0;i<list[v].size();i++){
			if(dist[list[v][i]]==-1){
				dist[list[v][i]]=dist[v]+1;
				q.push(list[v][i]);
			}
		}
	}

	return dist;
}

int main(){
	int n,e,u,v;
	cin >> n >> e;

	vector<int> list[n];

	for(int i=0;i<e;i++){
		cin >> u >> v;
		list[u].push_back(v);
	}

	vector<int > dist=shortestDistance(0,n,list);

	for(int i=0;i<n;i++)
		cout << dist[i] << " ";

}