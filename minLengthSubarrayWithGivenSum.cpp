#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin >> n >> k;

	int a[n];

	for(int i=0;i<n;i++)
		cin >> a[i];

	int start=0,end=-1,sum=0,min=INT_MAX;

	while(end<n){
		if(sum==k){
			if(end-start+1<min)
				min=end-start+1;

			sum+=a[++end];
		}

		if(sum<k){
			sum+=a[++end];
		}

		else{
			sum-=a[start++];
		}
	}

	cout << min << endl;

}