// Longest duplicate substring - leetcode

class Solution {
public:
    int m=19260827;
    vector<int> power;
    int d=26;
    
    string check(string &s,int k){
        map<int,vector<int> > match;
        int hash=0;
        
        for(int i=k-1;i>=0;i--){
            hash=(hash+(power[k-1-i]*(s[i]-'a'+1))%m)%m;
        }
        
        match[hash]={0};
        
        for(int i=k;i<s.length();i++){
            hash=((hash-power[k-1]*(s[i-k]-'a'+1))%m+m)%m;
            hash=((hash*d)%m+power[0]*(s[i]-'a'+1))%m;
            
            if(match.find(hash)==match.end()) match[hash]={i-k+1};
            else{
                for(int &idx:match[hash]){
                    if(s.substr(idx,k)==s.substr(i-k+1,k)) return s.substr(idx,k);
                }
                
                match[hash].push_back(i-k+1);
            }
        }
        
        return "";
        
    }
    
    string longestDupSubstring(string S) {
        int n=S.length();
        power.resize(n);
        
        power[0]=1;
        for(int i=1;i<n;i++) power[i]=(d*power[i-1])%m;
        
        int l=1,r=n;
        string ans="";
        
        while(l<=r){
            int mid=l+(r-l)/2;
            string str=check(S,mid);
            if(str!=""){
                ans=str;
                l=mid+1;
            }
                
            else r=mid-1;
        }
        
        return ans;  
    }
};