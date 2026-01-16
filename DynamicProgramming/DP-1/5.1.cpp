#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, m;
  cin >> n;
  vector<int> a_n(n);
  for (int i = 0; i < n; i++)
    cin >> a_n[i];
  cin >> m;
  vector<int> a_m(m);
  for (int i = 0; i < m; i++)
    cin >> a_m[i];
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a_n[i - 1] == a_m[j - 1])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  vector<int> res;
  int i = n, j = m;
  while (i > 0 && j > 0) {
    if (a_n[i - 1] == a_m[j - 1]) {
      res.push_back(a_n[i - 1]);
      i--;
      j--;
    } else if (dp[i - 1][j] >= dp[i][j - 1]) {
      i--;
    } else {
      j--;
    }
  }
  for (int k = res.size() - 1; k >= 0; k--)
    cout << res[k] << " ";
  cout << endl;
}
