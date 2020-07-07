#include<bits/stdc++.h>
using namespace std;

//watch : https://www.youtube.com/watch?v=4jY57Ehc14Y

//longest proper prefix which is also a suffix
vector<int> lpsUtil(string& pat){
	int m=pat.size();

	int i=1,len=0;

	vector<int> lps(m);
	lps[0]=0;

	while(i<m){
		if(pat[i]==pat[len]){
			lps[i]=len+1;
			len++;
			i++;

		} else{

			if(len!=0) len=lps[len-1];
			else{
				lps[i]=0;
				i++;
			} 
		}
	}

	return lps;
}

vector<int> kmp(string& text,string& pat){
	int n=text.size();
	int m=pat.length();

	int i=0,j=0;
	vector<int> res;
	vector<int> lps=lpsUtil(pat);

	while(i<n){
		if(text[i]==pat[j]){
			i++;
			j++;
		}

		else{
			if(j==0) i++;
			else j=lps[j-1];
		}

		if(j==m){
			res.push_back(i-j);
			j=lps[j-1];
		}
	}

	return res;
}

int main(){
	string text,pat;
	cin >> text >> pat;

	//start indices of matching pattern
	vector<int> v=kmp(text,pat);

	for(int i:v) cout << i << " ";
}