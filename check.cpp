#include<bits/stdc++.h>
using namespace std;

string print(string s){
	str="";
	int n=s.length();
	if(n==0)
		return str;
	str.push_back(s[0]);
	return str;
	int i=1;

	while(i<n){

		if(s[i]!=' '){
			i++;
			continue;
		}

		while(s[i]==' '){
			i++;
		}

		if(i<n){
			str.push_back(s[i]);
			i++;
		}
	}

	return str;
}

int main(){
	string s;
	getline(cin,s);

	cout << print(s);
}
