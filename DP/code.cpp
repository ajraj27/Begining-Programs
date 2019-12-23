#include<bits.stdc++.h>
using namespace std;

#define int long long int

int32_t main(){
	int ;
	cin >> t;

	while(t--){
		int n,x,a,b,l,r;
		cin >> n >> x >> a >> b;
		int tmp=min(a,b);
		if(tmp==a){
			l=a;
			r=b;
		}
		else{
			l=b;
			r=a;
		}

		if(l-1<x){
			l=1;
			x-=l-1;
		}

		else{
			l-=x;
			x=0;
		}

		if(x>0){
			if(x>n-r){
				r=n;
			}

			else
				r+=x;
		}

		cout << r-l << endl;

	}
}