#include<bits/stdc++.h>
using namespace std;

string LCSCount(string x,string y,int m,int n){
	int lcs[m+1][n+1];

	for(int i=0;i<m+1;i++)
		lcs[i][n]=0;
	for(int i=0;i<n+1;i++)
		lcs[m][i]=0;

	for(int i=m-1;i>=0;i--){
		for(int j=n-1;j>=0;j--){
			if(x[i]==y[j])
				lcs[i][j]=1+lcs[i+1][j+1];
			else
				lcs[i][j]=max(lcs[i+1][j],lcs[i][j+1]);
		}
	}

	int i=0,j=0;
	string str="";

	while(i<m && j<n){
		if(x[i]==y[j]){
			str.push_back(x[i]);
			i++;
			j++;
		}

		else if(lcs[i+1][j]>lcs[i][j+1])
			i++;
		else
			j++;
			
	}

	return str;
}

int main(){
	int m,n;
	cin >> m >> n;

	string x,y;
	cin >> x >> y;
	cout << LCSCount(x,y,m,n);
}