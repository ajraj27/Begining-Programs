#include<bits/stdc++.h>
using namespace std;

#define N 1000000

int a[N],bit[N+1];

void change(n){
	int temp[n];

	for(int i=0;i<n;i++)
		temp[i]=a[i];

	sort(temp,temp+n);

	for(int i=0;i<n;i++)
		a[i]=lower_bound(temp,temp+n,a[i])-temp+1;
}

int get_sum(int n,int idx){
	int sum=0;

	while(idx>0){
		sum+=bit[idx];
		idx-=(idx & -idx);
	}

	return sum;
}

void update(int n,int idx,int val){
	
	while(idx<=n){
		bit[idx]+=val;
		idx+=(idx & -idx);
	}
}

int main(){

	int n;
	cin >> n;

	for(int i=0;i<n;i++)
		cin >> a[i];

	change(n);

	int inv_count=0;

	for(int i=n-1;i>=0;i++){
		inv_count=get_sum(n,a[i]-1);
		update(n,a[i],1);
	}

	cout << inv_count;

}