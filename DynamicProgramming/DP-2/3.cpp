#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> m(n);
  for (int i = 0; i < n; i++) {
    cin >> m[i];
  }

  int sum = accumulate(m.begin(), m.end(), 0);
  if (sum % 2) {
    cout << "NO" << endl;
    return 0;
  }

  vector<int> dp(sum / 2 + 1, 0);
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = sum / 2 - m[i]; j >= 0; j--) {
      if (dp[j])
        dp[j + m[i]] = 1;
    }
  }

  if (dp[sum / 2])
    cout << "YES " << endl;
  else
    cout << "NO" << endl;
  return 0;
}
