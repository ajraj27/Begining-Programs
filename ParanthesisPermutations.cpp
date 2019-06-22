
#include<bits/stdc++.h>
using namespace std;

void allParanthesisUtil(int n,int open,int close,string str,vector<string>& res){
	if(close==n){
		res.push_back(str);
		return;
	}

	else{
		if(open>close){
			str.push_back(')');
			allParanthesisUtil(n,open,close+1,str,res);
			str.pop_back();
		}

		if(open<n){
			str.push_back('(');
			allParanthesisUtil(n,open+1,close,str,res);
			str.pop_back();
		}
	}
}

vector<string> allParanthesis(int n){
	vector<string> res;
	if(n==0)
		return res;

	string s="";

	allParanthesisUtil(n,0,0,s,res);
} 

int main(){
	int n;
	cin >> n;

	vector<string> temp=allParanthesis(n);

	for(int i=0;i<temp.size();i++)
		cout << temp[i] << endl;
	
}