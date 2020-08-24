#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
    freopen("inputf.txt", "r", stdin);
    freopen("outputf.txt", "w", stdout);
    #endif
int n;
cin>>n;
vector<int> a(n);
for(int i=0;i<n;i++)
    cin>>a[i];
sort(a.begin(),a.end());
int siz=(unique(a.begin(),a.end())-a.begin());
n=siz;
if(n==1){
    cout<<0<<endl;
    return 0;
}
int start=0,last=a[n-1]-a[0],mid,ans=last;
while(start<=last){
    int mid=(start+last)/2;
    int j=0;
    for(j=0;j<n&&(a[j]-a[0])<=2*mid;j++){

    }
    int prev=j;
    for(j=prev;j<n&&(a[j]-a[prev])<=2*mid;j++){

    }
    prev=j;
    for(j=prev;j<n&&(a[j]-a[prev])<=2*mid;j++){

    }
    if(j==n){
        ans=mid;
        last=mid-1;
    }
    else start=mid+1;
}
if(!ans){
    cout<<0<<endl;
    return 0;
}
double req=ans-0.5;
int j=0;
for(j=0;j<n&&(a[j]-a[0])<=2*req;j++){

}
int prev=j;
for(j=prev;j<n&&(a[j]-a[prev])<=2*req;j++){

}
prev=j;
for(j=prev;j<n&&(a[j]-a[prev])<=2*req;j++){

}
if(j==n)
    cout<<req<<endl;
else cout<<ans<<endl;
}