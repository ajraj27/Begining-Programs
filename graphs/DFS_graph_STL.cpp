#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DFSUtil(vector<int> adj[],vector<bool> &visited,int u)
{
    visited[u]=true;
    cout << u << " ";
    for(int i=0;i<adj[u].size();i++)
    {
        if(visited[adj[u][i]]==false)
           return DFSUtil(adj,visited,adj[u][i]);
    }
}

void DFS(vector<int> adj[],int n)
{
    vector<bool> visited(n,false);
    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)
            DFSUtil(adj,visited,i);
    }
}

int main()
{
    int n;
    n=5;

    vector<int> adj[n];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

    DFS(adj,n);

}