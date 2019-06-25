
#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> list[],int visited[],int src,int dest,int* count){
	visited[src]=1;

	if(src==dest){
		(*count)++;
	}

	else{
		for(int i=0;i<list[src].size();i++){
			if(!visited[list[src][i]]){
				dfs(list,visited,list[src][i],dest,count);
			}
		}
	}

	visited[src]=0;
}

int pathExist(vector<int> list[],int n,int src,int dest){
	int visited[n+1]={0};
	if(src==dest)
		return 1;

	int count=0;

	dfs(list,visited,src,dest,&count);
	return count;
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
