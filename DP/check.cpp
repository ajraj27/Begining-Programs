#include<bits/stdc++.h>
using namespace std;

string LCSCount(string A){
	int n=A.length();
	int lcs[n+1][n+1];

	for(int i=0;i<n+1;i++){
		lcs[i][n]=0;
		lcs[n][i]=0;
	}
	
	for(int i=n-1;i>=0;i--){
		for(int j=n-1;j>=0;j--){
			if(A[i]==A[j] && i!=j)
				lcs[i][j]=1+lcs[i+1][j+1];
			else
				lcs[i][j]=max(lcs[i+1][j],lcs[i][j+1]);
		}
	}

	return lcs[0][0];
}

int main(){
	string s;
	cin >> s;

	cout << LCSCount(s);
}