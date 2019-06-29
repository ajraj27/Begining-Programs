#include<bits/stdc++.h>
using namespace std;

int minTimeUtil(vector<int> inp,vector<int> freq,int low,int high,int level){

	if(low > high)
		return 0;

	int min=INT_MAX;
	for(int i=low;i<=high;i++){
		int val=minTimeUtil(inp,freq,low,i-1,level+1)+minTimeUtil(inp,freq,i+1,high,level+1)+level*freq[i];
		if(val<min)
			min=val;
	}

	return min;

}

int minTime(vector<int> inp,vector<int> freq){
	int n=inp.size();
	if(n==0)
		return 0;

	return minTimeUtil(inp,freq,0,n-1,1);
	
}



int main(){
	int n;
	cin >> n;

	vector<int> inp(n),freq(n);

	for(int i=0;i<n;i++)
		cin >> inp[i];

	for(int i=0;i<n;i++)
		cin >> freq[i];

	cout << minTime(inp,freq);
		
}