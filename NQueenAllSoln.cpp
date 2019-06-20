
#include<bits/stdc++.h>
using namespace std;

void solveNQueenUtil(int n,int row,vector<pair<int,int> >& v,vector<vector<string> >& res ){
	if(row==n){
		string str="";
		vector<string> temp;
		for(int i=0;i<v.size();i++){
			for(int j=0;j<n;j++){
				if(v[i].second==j)
					str.push_back('Q');
				else
					str.push_back('.');
			}

			temp.push_back(str);
			str="";
		}

		res.push_back(temp);
		return;
	}
		

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
			solveNQueenUtil(n,row+1,v,res);
		}
	}

}

vector<vector<string> > solveNQueen(int n){
	vector<vector<string> > res;

	if(n==2 || n==3)
		return res;

	vector<pair<int,int> > v(n);
	solveNQueenUtil(n,0,v,res);

	return res;
}

int main(){
	int n;
	cin >> n;

	vector<vector<string> > temp=solveNQueen(n);

	for(int i=0;i<temp.size();i++){
		for(int j=0;j<temp[i].size();j++)
			cout << temp[i][j] << endl;

		cout << endl;
	}

}