#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n;
  vector<int> a_n(n);
  for (int i = 0; i < n; i++) {
    cin >> a_n[i];
  }
  cin >> m;
  vector<int> a_m(m);
  for (int i = 0; i < m; i++) {
    cin >> a_m[i];
  }
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  int imax = 0;
  int jmax = 0;
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < m + 1; j++) {
      dp[i][j] = a_n[i - 1] == a_m[j - 1] ? dp[i - 1][j - 1] + 1 : 0;
      if (dp[i][j] > dp[imax][jmax]) {
        imax = i;
        jmax = j;
      }
    }
  }
  vector<int> ans(dp[imax][jmax]);
  for (int i = dp[imax][jmax]; i > 0; i--) {
    ans[i - 1] = a_n[i];
  }
  for (auto i : ans) {
    cout << i << ' ';
  }
  cout << endl;
}
