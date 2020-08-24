#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, x1, y1, x2, y2;
  cin >> n >> y1 >> x1 >> y2 >> x2;
  vector<int> nums(n);
  vector<vector<int>> sum(32, vector<int>(n+1, 0));
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
    int mask = 1;
    for (int b = 0; b < sum.size(); b++){
      sum[b][i + 1] = ((mask & nums[i]) > 0) + sum[b][i];
      mask <<= 1;
    }
  }
  y1--; x1--; y2--; x2--;
  int result = 0;
  for (int y = y1; y <= y2; y++) {
    int mask = 1;
    for (int b = 0; b < sum.size(); b++){
      result ^= ((mask & nums[y]) > 0) * (sum[b][x2 + 1] - sum[b][x1]) % 2 << b;
      mask <<= 1;
    }
  }
  cout << result << endl;
}