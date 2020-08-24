#include<bits/stdc++.h>
using namespace std;

vector<int> req={1,2,3,4,5,6,7,8,9};
set<int> p{3,5,7,11,13,17};
vector<pair<int,int> > s={{0,1},{0,3},{1,2},{1,4},{2,5},{3,4},{3,6},{4,5},{4,7},{5,8},{6,7},{7,8}};
map<vector<int>,int> m;

void solve(){
	queue<pair<vector<int>,int> >  q;

	q.push({req,0});
	m[req]=0;

	while(!q.empty()){
		auto z=q.front();
		q.pop();
		req=z.first;
		int c=z.second;

		for(auto &x:s){
			if(p.count(req[x.first]+req[x.second])){
				swap(req[x.first],req[x.second]);
				if(!m.count(req)){
					q.push({req,c+1});
					m[req]=c+1;
				}
				swap(req[x.first],req[x.second]);

			}
		}
	}

}


int main(){
	int t;
	cin >> t;
	solve();
	while(t--){
		vector<int> v(9);

		for(int i=0;i<9;i++) cin >> v[i];
		cout << (m.count(v)?m[v]:-1) << endl;
	}
}