
#include<bits/stdc++.h>
using namespace std;

int MaxDiff(vector<int> A){
	int n=A.size();
	if(n<2)
		return 0;

	int minVal=A[0],maxVal=A[0];

	for(int i=1;i<n;i++){
		minVal=min(minVal,A[i]);
		maxVal=max(maxVal,A[i]);
	}

	vector<int> minBucket(n-1,INT_MAX);
	vector<int> maxBucket(n-1,INT_MIN);

	float size=(float)(maxVal-minVal)/(float)(n-1);

	for(int i=0;i<n;i++){
		if(A[i]==minVal || A[i]==maxVal)
			continue;

		int index=(A[i]-minVal)/size;

		if(minBucket[index]==INT_MAX)
			minBucket[index]=A[i];
		else
			minBucket[index]=min(minBucket[index],A[i]);

		if(maxBucket[index]==INT_MIN)
			maxBucket[index]=A[i];
		else
			maxBucket[index]=min(maxBucket[index],A[i]);	

	}

	int prev=minVal;
	int max_diff=0;

	for(int i=0;i<n-1;i++){
		if(minBucket[i]==INT_MAX)
			continue;
		max_diff=max(max_diff,minBucket[i]-prev);
		prev=maxBucket[i];
	}

	max_diff=max(max_diff,maxVal-prev);

	return max_diff;



}


int main(){
    
    int n;
    cin >> n;

    vector<int> A(n);

    for(int i=0;i<n;i++)
    	cin >> A[i];

    cout << MaxDiff(A);
    
}
