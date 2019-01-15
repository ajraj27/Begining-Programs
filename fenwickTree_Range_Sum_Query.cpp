#include<bits/stdc++.h>
using namespace std;

#define N 1000000

int a[N],bit[N+1];

void update(int n,int idx,int val){
	idx++;

	while(idx<=n){
		bit[idx]+=val;
		idx+=(idx & -idx);
	}
}

void buildBIT(int n){
	for(int i=0;i<n;i++)
		update(n,i,a[i]);

}

int query(int n,int idx){
	idx++;
	int sum=0;

	while(idx>0){
		sum+=bit[idx];
		idx-=(idx & -idx);
	}

	return sum;

}

int main(){
	int n,q,type,val,idx;
	cin >> n;

	for(int i=0;i<n;i++)
		cin >> a[i];

	buildBIT(n);

	cin >> q;

	while(q--){
		cin >> type >> idx;

		if(type==1){
			cin >> val;
			update(n,idx,val);
		}

		else{
			int ans=query(n,idx);
			cout << ans << endl;
		}
	}


}