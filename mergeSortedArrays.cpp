#include<bits/stdc++.h>
using namespace std;

double getMedian(int a[],int b[],int n1,int n2){
	if(n1>n2)
		return getMedian(b,a,n2,n1);

	int low=0,high=n1;

	while(low<=high){
		int parta=low+(high-low)/2;
		int partb=(n1+n2+1)/2-parta;

		int maxlefta=parta==0?INT_MIN:a[parta-1];
		int minrighta=parta==n1?INT_MAX:a[parta];

		int maxleftb=partb==0?INT_MIN:b[partb-1];
		int minrightb=partb==n2?INT_MAX:b[partb];

		if(maxlefta<=minrightb && maxleftb<=minrighta){
			if((n1+n2)%2==0)
				return ((double)max(maxlefta,maxleftb)+min(minrighta,minrightb))/2;
			else
				return (double)(max(maxlefta,maxleftb));
		}

		else if(maxlefta>minrightb)
			high=parta-1;
		else
			low=parta+1;

	}
}

int main(){
	int n1,n2;
	cin >> n1 >> n2;
	int a[n1],b[n2];

	for(int i=0;i<n1;i++)
		cin >> a[i];

	for(int i=0;i<n2;i++)
		cin >> b[i];

	cout << getMedian(a,b,n1,n2);
}