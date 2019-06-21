
#include<bits/stdc++.h>
using namespace std;

void getPermutationsUtil(int level,vector<int> A,vector<vector<int> >& res,vector<bool> used,vector<int> curr,int n){
	if(level==n){
		res.push_back(curr);
		return;
	}

	for(int i=0;i<n;i++){
		
		if(!used[i]){
			used[i]=true;
			curr.push_back(A[i]);
			getPermutationsUtil(level+1,A,res,used,curr,n);
			curr.pop_back();
			used[i]=false;
		}


	}

}

vector<vector<int> > getPermutations(vector<int> A){
	int n=A.size();
	vector<vector<int> > res;

	if(n==0)
		return res;
	
	vector<bool> used(n,false);
	vector<int> curr;
	getPermutationsUtil(0,A,res,used,curr,n);
	return res;
}

int main(){
	int n;
	cin >> n;

	vector<int> v(n);

	for(int i=0;i<n;i++)
		cin >> v[i];

	vector<vector<int> > temp=getPermutations(v);

	for(int i=0;i<temp.size();i++){
		for(int j=0;j<temp[i].size();j++)
			cout << temp[i][j] << " ";
		cout << endl;
	}
}