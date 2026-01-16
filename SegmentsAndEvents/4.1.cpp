#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<int>> t_raw(n, vector<int>(6));
  for (int i = 0; i < n; i++) {
    cin >> t_raw[i][0] >> t_raw[i][1] >> t_raw[i][2] >> t_raw[i][3] >>
        t_raw[i][4] >> t_raw[i][5];
  }

  int counter{0};

  vector<pair<int, int>> t(2 * n);
  for (int i = 0; i < n; i++) {
    t[2 * i].first = t_raw[i][0] * 3600 + t_raw[i][1] * 60 + t_raw[i][2];
    t[i * 2 + 1].first = t_raw[i][3] * 3600 + t_raw[i][4] * 60 + t_raw[i][5];
    if (t[i * 2].first == t[i * 2 + 1].first) {
      counter++;
      t[i * 2].second = t[i * 2 + 1].second = 0;
    } else if (t[i * 2].first < t[i * 2].first) {
      t[i * 2].second = 1;
      t[i * 2 + 1].second = -1;
    } else {
      t[i * 2].second = -1;
      t[i * 2 + 1].second = 1;
      t.push_back(pair<int, int>(0, 1));
      t.push_back(pair<int, int>(24 * 3600, -1));
    }
  }

  t.push_back(pair<int, int>(0, 0));
  sort(t.begin(), t.end(), [](const auto &a, const auto &b) {
    if (a.first == b.first)
      return a.second < b.second;
    return a.first < b.first;
  });
  t.push_back(pair<int, int>(24 * 3600, 0));

  int ans{0};
  for (int i = 0; i < (int)t.size() - 1; i++) {
    counter += t[i].second;
    if (counter == n) {
      ans += t[i + 1].first - t[i].first;
    }
  }

  cout << ans << endl;
}
