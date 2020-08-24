// N intervals are given with some weights. Find two non-overlapping intervals hving max sum.

#include <bits/stdc++.h>
using namespace std;
 
int maxScore(vector<vector<int>> &arr){
	sort(arr.begin(), arr.end(), [&](vector<int> &a, vector<int> &b){
		if(a[0] == b[0])return a[1] < b[1];
		return a[0] < b[0];
	});
	int N = arr.size();
	int max_profit = arr[N - 1][2];
	set<pair<int, int>> st;
	st.insert({arr[N - 1][0], arr[N - 1][2]});
	for(int i = N - 2; i >= 0; i--){
		auto it = st.lower_bound({arr[i][1] + 1, -1});
		if(it != st.end()){
			max_profit = max(max_profit, it->second + arr[i][2]);
			auto it2 = st.lower_bound({arr[i][0], -1});
			if(it2 != st.end()){
				st.insert({arr[i][0], max(arr[i][2], it2->second)});
			}
			else{
				st.insert({arr[i][0], max(it->second, arr[i][2])});
			}
		}
		else{
			max_profit = max(max_profit, arr[i][2]);
			auto it2 = st.lower_bound({arr[i][0], -1});
 
			if(it2 != st.end()){
				st.insert({arr[i][0], max(arr[i][2], it2->second)});
			}
			else{
				st.insert({arr[i][0], arr[i][2]});
			}
		}
	}
	return max_profit;
}
 
int main() {
	int N;
	cin >> N;
	vector<vector<int>> arr(N, vector<int>(3));
	for(int i = 0; i < N; i++){
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}
	cout << maxScore(arr);
	return 0;
}