#include<bits/stdc++.h>
using namespace std;

struct node{
	map<char,struct node*> m;
	bool end;
};

#define struct node node;

node* getNode(){
	node* newNode=new node;
	newNode->end=false;
	return newNode;
}

void insert(node* root,string key){
	node* curr=root;

	for(int i=0;i<key.length();i++){
		if((curr->m).find(key[i])==(curr->m).end()){
			node* newNode=getNode();
			(curr->m)[key[i]]=newNode;
		}

		curr=(curr->m)[key[i]];
	}

	curr->end=true;
}

bool search(node* root,string word){
	node* curr=root;

	for(int i=0;i<word.length();i++){
		if((curr->m).find(word[i])==(curr->m).end())
			return false;

		curr=(curr->m)[word[i]];
	}

	return curr!=NULL && curr->end;
}

bool isLastNode(node* curr){
	return (curr->m).size()==0;
}

void printRec(node* root,string currPrefix){
	if(root->end==true)
		cout << currPrefix << endl;

	if(isLastNode(root))
		return ;

	map<char,node*> :: iterator it;

	for(it=(root->m).begin();it!=(root->m).end();it++){
		currPrefix.push_back(it->first);
		printRec(it->second,currPrefix);
		currPrefix.pop_back();
	}
}


int prefixSearch(node* root,string prefix){
	node* curr=root;

	for(int i=0;i<prefix.length();i++){
		if((curr->m).find(prefix[i])==(curr->m).end())
			return 0;

		curr=(curr->m)[prefix[i]];
	}

	bool isWord=curr->end==true;
	bool last=isLastNode(curr);

	if(isWord && last){
		cout << prefix << endl;
		return -1;
	}

	if(!last){
		printRec(curr,prefix);
		return 1;
	}

}

int main(){
	int n;
	cin >> n;

	string s,str;

	node* root=getNode();

	for(int i=0;i<n;i++){
		cin >> s;
		insert(root,s);
	}

	int q;
	cin >> q;

	while(q--){
		cin >> str;
		cout << search(root,str) << endl;
	}

	cin >> str;
	int flag=prefixSearch(root,str);

	if(flag==-1)
		cout << "No string found with this prefix" << endl;
	if(flag==0)
		cout << "No other strings with this prefix" << endl;

}