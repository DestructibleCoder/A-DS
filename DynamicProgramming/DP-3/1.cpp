#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<int> dp(n, 0);
  dp[0] = dp[1] = a[1] - a[0];
  for (int i = 2; i < dp.size(); i++) {
    if (dp[i - 1] < dp[i - 2]) {
      dp[i] = dp[i - 1] + a[i] - a[i - 1];
    } else {
      dp[i] = dp[i - 2] + a[i] - a[i - 1];
    }
  }
  cout << dp[n - 1] << endl;
}
