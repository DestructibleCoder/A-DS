#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<int>> p(n + 1, vector<int>(4));
  for (int i = 1; i < n; i++) {
    cin >> p[i][0] >> p[i][1] >> p[i][2];
    p[i][1] = p[i][0] + p[i][1];
    p[i][3] = i;
  }

  sort(p.begin(), p.end(),
       [](const auto &a, const auto &b) { return a[1] < b[1]; });

  vector<int> dp(n + 1, 0);
  for (int i = 1; i < n + 1; i++)
}
