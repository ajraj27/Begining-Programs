
#include<bits/stdc++.h>
using namespace std;

string findSubString(string org,string pat){
	int orglen=org.length();
	int patlen=pat.length();

	int orgFreq[256]={0};
	int patFreq[256]={0};

	for(int i=0;i<patlen;i++)
		patFreq[pat[i]]++;

	int start=0,start_idx=-1,mini=INT_MAX,count=0;

	for(int i=0;i<orglen;i++){
		orgFreq[org[i]]++;

		if(patFreq[org[i]]!=0 && orgFreq[org[i]]<=patFreq[org[i]])
			count++;

		if(count==patlen){
			while(orgFreq[org[start]]>patFreq[org[start]] || patFreq[org[start]]==0){
				//if(orgFreq[org[start]]>patFreq[org[start]])
					orgFreq[org[start]]--;
				start++;
			}

			int len_window=i-start+1;
			if(len_window<mini){
				mini=len_window;
				start_idx=start;
			}
		}
	}

	if(start_idx==-1)
		return "";

	return org.substr(start_idx,mini);
}


int main(){
	string org,pat;
	getline(cin,org);
	getline(cin,pat);

	string temp=findSubString(org,pat);

	cout << temp;
}