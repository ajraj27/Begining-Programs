#include<bits/stdc++.h>
using namespace std; 

void printArray(char arr[],int n){
	for(int i=0;i<n;i++)
		cout << arr[i];

	cout << endl;
}

void printPermutationsUtil(char str[],char res[],int count[],int level){

	if(level==strlen(res)){
		printArray(res,strlen(res));
		return;
	}

	for(int i=0;i<strlen(str);i++){
		if(count[i]==0)
			continue;

		res[level]=str[i];
		count[i]--;
		printPermutationsUtil(str,res,count,level+1);
		count[i]++;
	}
	
}

void printPermutations(string s){
	int n=s.length();
	map<char,int> m;
	map<char,int> :: iterator it;

	for(int i=0;i<n;i++)
		m[s[i]]++;

	cout << m.size()<<endl;

	char str[m.size()];
	char res[n];
	int count[m.size()];
	int idx=0;

	for(it=m.begin();it!=m.end();it++){
		str[idx]=it->first;
		count[idx]=it->second;
		idx++;	
	}

	str[idx]='\0';

	printPermutationsUtil(str,res,count,0);

}




int main(){
	string s;
	cin >> s;

	printPermutations(s);

	return 0;
}