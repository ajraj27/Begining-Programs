#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin >> n >> k;

	int a[n+1],b[n+1];

	for(int i=1;i<=n;i++)
		cin >> a[i];

	sort(a,a+n+1);

	int c=1;
	bool flag=true;
	b[1]=1;

	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]){
			if(c<=k)
				b[i]=c++;
			else{
				flag=false;
				break;
			}
		}

		else
			b[i]=c;


	}

	if(flag){
		cout << "YES" << endl;
		for(int i=1;i<=n;i++)
			cout << b[i] << " " ;
	}

	else
		cout << "NO";
}