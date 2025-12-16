#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, M;
  cin >> n >> M;

  vector<int> m(n);
  for (int i = 0; i < n; i++)
    cin >> m[i];

  vector<int> c(n);
  for (int i = 0; i < n; i++)
    cin >> c[i];

  vector<int> dp(M + 1, -1);
  dp[0] = 0;

  for (int i = 0; i < n; i++) {
    for (int j = M - m[i]; j >= 0; j--) {
      if (dp[j] != -1) {
        dp[j + m[i]] = max(dp[j + m[i]], dp[j] + c[i]);
      }
    }
  }
  cout << *max_element(dp.begin(), dp.end()) << endl;
}
