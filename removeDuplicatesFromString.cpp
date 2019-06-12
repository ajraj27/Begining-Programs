#include<bits/stdc++.h>
using namespace std;

string removedupliactes(string s){
	int n=s.length();
	int prev=-1;
	int i=0;

	while(i<n){
		if(prev==-1 || s[prev]!=s[i]){
			prev++;
			s[prev]=s[i];
			i++;
		}
		else{
			while(i<n && s[prev]==s[i]){
				i++;
				prev--;
			}
		}
	}

	s[prev+1]='\0';

	return s;
	

}

int main(){
	string s;
	cin >> s;

	string str=removedupliactes(s);
	int i=0;

	while(str[i]!='\0'){
		cout << str[i];
		i++;
	}

}