#include<bits/stdc++.h>
using namespace std;

int knapsack(int n,int w,int val[],int wt[]){
	int ks[n+1][w+1];

	for(int i=0;i<n+1;i++)
		ks[i][0]=0;

	for(int i=0;i<w+1;i++)
		ks[0][i]=0;

	for(int item=1;item<=n;item++){
		for(int cap=1;cap<=w;cap++){

			if(wt[item-1]<=cap)
				ks[item][cap]=max(ks[item-1][cap],val[item-1]+ks[item-1][cap-wt[item-1]]);
			else
				ks[item][cap]=ks[item-1][cap];
		}
	}

	return ks[n][w];
}

int main(){
	int n,w;
	cin >> n >> w;

	int val[n],wt[n];

	for(int i=0;i<n;i++)
		cin >> val[i];
	for(int i=0;i<n;i++)
		cin >> wt[i];

	cout << knapsack(n,w,val,wt);
}