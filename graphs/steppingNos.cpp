#include<bits/stdc++.h>
using namespace std;

void dfs(int A,int B,int num,vector<int>& res){
	if(num>B)
		return;
	if(num>=A)
		res.push_back(num);

	int last=num%10;

	if(last==0)
		dfs(A,B,num*10+last+1,res);
	else if(last==9)
		dfs(A,B,num*10+last-1,res);
	else{
		dfs(A,B,num*10+last+1,res);
		dfs(A,B,num*10+last-1,res);
	}
}

vector<int> steppingnos(int A,int B){
	vector<int> res;

	if(A>B)
		return res;

	if(A==0)
		res.push_back(0);

	for(int i=1;i<10;i++)
		dfs(A,B,i,res);

	sort(res.begin(),res.end());

	return res;
}

int main(){
	int m,n;
	cin >> m >> n;

	vector<int> temp=steppingnos(m,n);

	for(int i=0;i<temp.size();i++)
		cout << temp[i] << " ";	
}