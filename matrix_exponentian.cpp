//To find f(n)=(m-1)*(f(n-1)+f(n-2)), f(0)=m,f(1)=m*m. Given - n,m.
#include <bits/stdc++.h>
using namespace std; 
#define ll long long int
  
/* Helper function that multiplies 2 matrices F and M of size 2*2, and 
  puts the multiplication result back to F[][] */
const int mod=1e9+7;
  
/* Helper function that calculates F[][] raise to the power n and puts the 
  result in F[][] 
  Note that this function is designed only for fib() and won't work as general 
  power function */

void multiply(ll F[2][2], ll M[2][2]) 
{ 
  ll x =  (F[0][0]*M[0][0] + F[0][1]*M[1][0])%mod; 
  ll y =  (F[0][0]*M[0][1] + F[0][1]*M[1][1])%mod; 
  ll z =  (F[1][0]*M[0][0] + F[1][1]*M[1][0])%mod; 
  ll w =  (F[1][0]*M[0][1] + F[1][1]*M[1][1])%mod; 
  
  F[0][0] = x; 
  F[0][1] = y; 
  F[1][0] = z; 
  F[1][1] = w; 
} 

void power(ll F[2][2], ll n,ll m) 
{ 
  if( n == 0 || n == 1) 
      return; 
  
  ll M[2][2] = {{m-1,m-1},{1,0}}; 
  
  power(F, n/2,m); 
  multiply(F, F); 
  
  if (n%2 != 0) 
     multiply(F, M); 
} 
  
  
int fib(ll n,ll a,ll b,ll m) 
{ 
  ll F[2][2] = {{m-1,m-1},{1,0}}; 
  if (n == 0) 
      return 0; 
  power(F, n-1,m); 
  
  return ((F[0][0]*b)%mod+(F[0][1]*a)%mod)%mod; 
} 
  

  

/* Driver program to test above function */
int main() 
{ 
 	ll n,m,t;
 	cin >> t;

 	while(t--){
 		cin >> n >> m;
 		m=m%mod;
	 	if(n==1) cout << m << endl;
	 	else if(n==2) cout << (m*m)%mod << endl;
	 	else cout << fib(n-1,m,(m*m)%mod,m) << endl;
 	}
 	
} 
