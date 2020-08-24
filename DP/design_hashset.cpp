#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'getMinInsertions' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY firstArray
 *  2. INTEGER_ARRAY secondArray
 */

int getList(vector<int>& v){
    vector<int> res;
        
    for(int i=0;i<v.size();i++){
        int x=v[i];
        auto it=lower_bound(res.begin(),res.end(),x);
        if(it==res.end()) res.push_back(x);
        else *it=x;
    }
    
    return res.size();
}
int getMinInsertions(vector<int> firstArray, vector<int> secondArray) {
    int n1=firstArray.size();
    int n2=secondArray.size();

   map<int,int> m;
    vector<int> v;
   for(int i=0;i<n1;i++) if(m.find(firstArray[i])==m.end()) m[firstArray[i]]=i;

   for(int i=0;i<n2;i++ ){
       if(m.find(secondArray[i])!=m.end()){
           v.push_back(m[secondArray[i]]);
       }   
   }

   int t=getList(v);
   return n2-t;
}

int main()