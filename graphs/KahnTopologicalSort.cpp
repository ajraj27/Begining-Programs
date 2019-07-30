
#include<bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<int> list[],int n,int e){
	int indegree[n]={0};
	queue<int> q;
	vector<int> v;
	vector<int> empty;
	int ctr=0;

	for(int i=0;i<n;i++){
		for(int j=0;j<list[i].size();j++)
			indegree[list[i][j]]++;
	}

	for(int i=0;i<n;i++){
		if(indegree[i]==0)
			q.push(i);
	}

	while(!q.empty()){
		int num=q.front();
		q.pop();
		v.push_back(num);

		for(int i=0;i<list[num].size();i++){
			indegree[list[num][i]]--;
			if(indegree[list[num][i]]==0)
				q.push(list[num][i]);
		}

		ctr++;
	}

	if(ctr!=n)
		return empty;

	return v;
}


int main(){
	int n,e,u,v;
	cin >> n >> e;

	vector<int> list[n];

	for(int i=0;i<e;i++){
		cin >> u >> v;
		list[u].push_back(v);
	}

	vector<int> temp=topologicalSort(list,n,e);

	if(temp.size()>0){
		for(int i=0;i<n;i++)
			cout << temp[i] << " ";
	}

	else
		cout << "Cycle exists";
	
}