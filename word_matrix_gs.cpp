#include<bits/stdc++.h>
using namespace std;

int poss(int x,int y,int n){
	if(x<0 || y<0 || x>=n || y>=n) return 0;
	return 1;
}

int solve(int n,vector<string>& v,string& word){

	int dx[]={-1,0,1,1,1,0,-1,-1};
	int dy[]={1,1,1,0,-1,-1,-1,0};

	int cnt=0;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(v[i][j]==word[0]){
				if(word.length()==1){
					cnt++;
					continue;
				}
				
				for(int k=0;k<8;k++){
					int l,x=i,y=j;
					for(l=1;l<word.length();l++){
						int nx=x+dx[k],ny=y+dy[k];
						if(poss(nx,ny,n) && v[nx][ny]==word[l]){
							x=nx,y=ny;
							continue;
						}

						else break;
	
					}

					if(l==word.length()) cnt++;


					
				}
			}
		}
	}

	return cnt;
}

int main(){
	int n;
	cin >> n;
	string word;

	vector<string> v(n);
	for(int i=0;i<n;i++) cin >> v[i];
	cin >> word;

	cout << solve(n,v,word);	
}