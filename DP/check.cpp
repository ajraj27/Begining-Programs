#include<bits.stdc++.h>
using namespace std;

void nextPermutation(vector<int>& A){
	int n=A.size();
	int idx=-1,idx2;

	for(int i=n-2;i>=0;i--){
		if(A[i]<A[i+1]){
			idx=i;
			break;
		}
	}

	if(idx==-1){
		sort(A.begin(),A.end());
		return;
	}

	for(int i=idx;i<n;i++){
		if(A[i]>A[idx])
			idx2=i;
	}

	swap(A[idx],A[idx2]);

	sort(A.begin()+idx+1,A.end());
}

int main(){
	int n;
	cin >> n;

	vector<int> v(n,0);

	for(int i=0;i<n;i++)
		cin >> v[i];

	nextPermutation(v);

	for(int i=0;i<v.size();i++)
		cin >> v[i] << " ";

}