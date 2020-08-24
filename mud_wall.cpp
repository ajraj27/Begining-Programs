#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& pos,vector<int>& height){
	int n=pos.size();
	int m=height.size();

	int mx=0;

	for(int i=0;i<n-1;i++){
		if(pos[i]<pos[i+1]-1){
			int hdiff=abs(height[i+1]-height[i]);
			int gap=pos[i+1]-pos[i]-1;
			int lmax=0;

			if(gap>hdiff){
				int l=max(height[i+1],height[i])+1;
				int rem=gap-hdiff-1;
				lmax=l+rem/2;
			} else lmax=min(height[i+1],height[i])+gap;

			mx=max(mx,lmax);
		}
		
	}

	return mx;
}

int main(){
	int n;
	cin >> n;

	vector<int> pos(n),height(n);

	for(int i=0;i<n;i++) cin >> pos[i];
	for(int i=0;i<n;i++) cin >> height[i];

	cout << solve(pos,height);
}