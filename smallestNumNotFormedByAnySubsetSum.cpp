#include<bits/stdc++.h>
using namespace std;

int getSmallestNum(int a[],int n){
	if(n==0 || a[0]!=1)
		return 1;

	int maxi=1;

	for(int i=1;i<n;i++){
		if(a[i]>maxi+1)
			break;

		maxi+=a[i];
	}

	return maxi+1;
}

int main(){
	int n;
	cin >> n;

	int a[n];

	for(int i=0;i<n;i++)
		cin >> a[i];

	cout << getSmallestNum(a,n) << endl;
}