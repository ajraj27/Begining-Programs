#include<bits/stdc++.h>
using namespace std;

struct el{
	int val;
	int idx;
	int nextidx;
};

struct cmp{
	bool operator()(const el& a,const el& b){
		return a.val>b.val;
	}
};

int main(){
	int n,k;
	cin >> n >> k;
	int v[k][n];
	vector<int> res;
	el temp;

	for(int i=0;i<k;i++){
		for(int j=0;j<n;j++){
			cin >> v[i][j];
		}
	}

	priority_queue<el,vector<el>,cmp> pq;
	for(int i=0;i<k;i++){
		temp.val=v[i][0];
		temp.idx=i;
		temp.nextidx=1;
		pq.push(temp);
	}

	for(int count=0;count<n*k;count++){
		temp=pq.top();
		pq.pop();
		res.push_back(temp.val);

		if(temp.nextidx<n){
			temp.val=v[temp.idx][temp.nextidx];
			temp.nextidx+=1;
			pq.push(temp);
		}
	}

	for(int i=0;i<res.size();i++){
		cout << res[i] << " ";
	}

		
}