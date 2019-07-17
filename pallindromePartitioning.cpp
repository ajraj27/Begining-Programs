#include<bits/stdc++.h>
using namespace std;

int pallindrome(string str){
	int n=str.length();

	for(int i=0;i<n/2;i++)
		if(str[i]!=str[n-i-1])
			return 0;

	return 1;	
}

void backtrack(vector<vector<string> >&res,vector<string> curr,int n,string s,int level){
	if(level==n){
		res.push_back(curr);
		return;
	}

	string str="";
	for(int i=level;i<n;i++){
		str+=s[i];
		if(pallindrome(str)){
			curr.push_back(str);
			backtrack(res,curr,n,s,i+1);
			curr.pop_back();
		}
	}
}

vector<vector<string> > getAll(string s){
	vector<vector<string> > res;
	vector<string> curr;
	int n =s.length();

	backtrack(res,curr,n,s,0);
	return res;
}

int main(){
	string s;
	cin >> s;

	vector<vector<string> > v=getAll(s);

	for(int i=0;i<v.size();i++){
		for(int j=0;j<v[i].size();j++)
			cout << v[i][j] << " ";
		cout << endl;
	}
}