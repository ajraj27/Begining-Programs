
#include<bits/stdc++.h>
using namespace std;
int rowValid(vector<string> A,int row,char ch,int n){
    for(int i=0;i<n;i++){
    	if(A[row][i]==ch)
    		return 0;
    }

    return 1;
}

int columnValid(vector<string> A,int column,char ch,int n){
     for(int i=0;i<n;i++){
    	if(A[i][column]==ch)
    		return 0;
    }

    return 1;
}

int boxValid(vector<string> A,int row,int column,char ch){

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
           if(A[row+i][column+j]==ch)
           	return 0;
        }
    }

    return 1;
}

int canPlace(vector<vector<char> > A,int row,int column,char ch,int n){
    return rowValid(A,row,ch,n) && columnValid(A,column,ch,n) && boxValid(A,row-row%3,column-column%3,ch);
}


bool solveSudokuUtil(vector<vector<char> >& A,int n,int row,int col){
	if(col==A[row].size()){
		col=0;
		row++;

		if(row==A.size())
			return true;
	}

	if(A[row][col]!='.')
		return solveSudokuUtil(A,n,row,col+1);

	for(int value=1;value<=9;i++){
		char ch=value+'0';

		if(canPlace(A,row,col,ch)){
			A[row][col]=ch;
			if(solveSudokuUtil(A,n,row,col+1))
				return true;
		}
	}

	A[row][col]='.';
	return false;
}

void solveSudoku(vector<vector<char> >& A){
	int n=A.size();
	bool place=solveSudokuUtil(A,n,0,0);
}

int main(){

}