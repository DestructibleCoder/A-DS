#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> s(2 * n, vector<int>(3));

  for (int i = 0; i < n; i++) {
    cin >> s[2 * i][0] >> s[i * 2 + 1][0];
    if (s[i * 2][0] > s[i * 2 + 1][0]) {
      s[i * 2][1] = 1;
      s[i * 2 + 1][1] = -1;
    } else {
      s[i * 2][1] = -1;
      s[i * 2 + 1][1] = 1;
    }
  }

  vector<vector<int>> p(m, vector<int>(3));
  for (int i = 0; i < m; i++) {
    cin >> p[i][0];
    p[i][2] = i;
    s.push_back(p[i]);
  }

  sort(p.begin(), p.end());
  sort(s.begin(), s.end(), [](const auto &a, const auto &b) {
    if (a[0] == b[0])
      return a[1] < b[1];
    return a[0] < b[0];
  });

  int counter{0};
  int pi = 0;
  for (int i = 0; i < m + n * 2; i++) {
    if (s[i][1] == 0) {
      p[pi][0] = -counter;
      pi++;
    }
    counter += s[i][1];
  }

  sort(p.begin(), p.end(),
       [](const auto &a, const auto &b) { return a[2] < b[2]; });

  for (auto point : p)
    cout << point[0] << ' ';
  cout << endl;
}
