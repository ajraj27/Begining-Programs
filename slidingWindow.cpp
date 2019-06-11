#include<bits/stdc++.h>
using namespace std;

void getMaxWindow(int n,int k,int a[],int b[]){
	if(k>n)
		return;

	deque<int> q;

	for(int i=0;i<k;i++){
		while(!q.empty() && a[i]>=a[q.back()])
			q.pop_back();
		q.push_back(i);
	}

	for(int i=k;i<n;i++){
		b[i-k]=a[q.front()];
		while(!q.empty() && a[i]>=a[q.back()])
			q.pop_back();

		while(!q.empty() && q.front()<=i-k)
			q.pop_front();

		q.push_back(i);
	}

	b[n-k]=a[q.front()];
}


int main(){
	int n,k;
	cin >> n >> k;

	int a[n],b[n-k+1];

	for(int i=0;i<n;i++)
		cin >> a[i];

	getMaxWindow(n,k,a,b);	

	for(int i=0;i<n-k+1;i++)
		cout << b[i] << " ";
}