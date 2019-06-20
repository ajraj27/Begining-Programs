
#include<bits/stdc++.h>
using namespace std;

bool solveNQueenUtil(int n,int row,vector<pair<int,int> >& v){
	if(row==n)
		return true;

	for(int col=0;col<n;col++){
		bool foundSafe=true;

		for(int queen=0;queen<row;queen++){
			if(v[queen].second==col || v[queen].first-v[queen].second==row-col || v[queen].first+v[queen].second==row+col){
				foundSafe=false;
				break;
			}
		}

		if(foundSafe){
			v[row]=make_pair(row,col);
			if(solveNQueenUtil(n,row+1,v))
				return true;
		}
	}

	return false;
}

vector<pair<int,int> > solveNQueen(int n){
	vector<pair<int,int> > v(n);
	vector<pair<int,int> > temp;

	bool hasSolution=solveNQueenUtil(n,0,v);

	if(hasSolution)
		return v;
	else
		return temp;
}

int main(){
	int n;
	cin >> n;

	vector<pair<int,int> > temp=solveNQueen(n);

	if(temp.size()>0){
		for(int i=0;i<temp.size();i++)
			cout << temp[i].first<< " "<<temp[i].second << endl;
	}

	else
		cout << "Not possible.";
	
}