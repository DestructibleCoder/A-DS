#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, M;
  cin >> n >> M;

  vector<int> m(n);
  for (int i = 0; i < n; i++)
    cin >> m[i];

  vector<int> dp(M + 1, 0);
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = M - m[i]; j >= 0; j--) {
      if (dp[j])
        dp[j + m[i]] = 1;
    }
  }
  if (dp[M])
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
