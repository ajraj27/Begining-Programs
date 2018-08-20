#include<bits/stdc++.h>
using namespace std;

bool cmp(const pair<int,int> &a,const pair<int,int> &b)
{
	if(a.second>b.second)
		return true;

	if(a.second==b.second && a.first<b.first)
		return true;

	return false;
}

void addEdge(vector<pair<int,int> > adj[],int u,int v,vector<pair<int,int> >vec)
{
	adj[u].push_back(vec[v]);
	adj[v].push_back(vec[u]);
}

int main()
{
	int n,m,k,val,u,v;
	cin >> n >> m >> k;
	vector<pair<int,int> > vec;
	vector<pair<int,int> > adj[n+1];

	vec.push_back(make_pair(-1,-1));

	for(int i=1;i<=n;i++)
	{
		cin >> val;
		vec.push_back(make_pair(i,val));
	}

	for(int i=0;i<m;i++)
	{
		cin >> u >> v;
		addEdge(adj,u,v,vec);
	}

	for(int i=1;i<=n;i++)
	{
		sort(adj[i].begin(),adj[i].end(),cmp);
	}

	for(int i=1;i<=n;i++)
	{
		//if(adj[i].size()<k)
			//cout <<-1 << endl;

		//else
			cout << adj[i][k-1].first<<endl;
	}



}