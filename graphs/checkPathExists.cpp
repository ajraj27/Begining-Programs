
#include<bits/stdc++.h>
using namespace std;

int dfs(vector<int> list[],int visited[],int src,int dest){
	visited[src]=1;

	if(src==dest)
		return 1;

	for(int i=0;i<list[src].size();i++){
		if(!visited[list[src][i]]){
			if(dfs(list,visited,list[src][i],dest))
				return 1;
		}
	}

	return 0;
}

int pathExist(vector<int> list[],int n,int src,int dest){
	int visited[n+1]={0};
	if(src==dest)
		return 1;

	return dfs(list,visited,src,dest);

}

int main(){
    int n,e,u,v,src,dest;
    cin >> n >> e;

    vector<int> list[n+1];

    for(int i=0;i<e;i++){
    	cin >> u >> v;
    	list[u].push_back(v);
    	list[v].push_back(u);
    }

    cin >> src >> dest;

    cout << pathExist(list,n,src,dest); 
}
