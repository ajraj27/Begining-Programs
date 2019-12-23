#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;

	while(t--){
		int n,k;
		cin >> n >> k;
		string s;
		cin >> s;
		int ctr=0;
		vector<int> v;
		s.append('0');

		for(int i=0;i<n;i++){
			if(s[i]=='1'){
				ctr++;
				continue;
			}

			v.push_back(ctr);
			ctr=0;
			tmp=i;
		}

		while(k>0){

		}
	}
}