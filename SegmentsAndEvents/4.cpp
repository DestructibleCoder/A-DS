#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<vector<int>> ts(n, vector<int>(6));
  for (int i = 0; i < n; i++)
    cin >> ts[i][0] >> ts[i][1] >> ts[i][2] >> ts[i][3] >> ts[i][4] >> ts[i][5];

  int counter{0};
  vector<pair<int, int>> t(n * 2);
  for (int i = 0; i < n; i++) {
    t[i * 2].first = ts[i][0] * 3600 + ts[i][1] * 60 + ts[i][2];
    t[i * 2 + 1].first = ts[i][3] * 3600 + ts[i][4] * 60 + ts[i][5];
    if (t[i * 2].first == t[i * 2 + 1].first) {
      counter++;
      t[i * 2].second = t[i * 2 + 1].second = 0;
    } else {
      if (t[i * 2].first > t[i * 2 + 1].first)
        counter += 1;
      t[i * 2].second = 1;
      t[i * 2 + 1].second = -1;
    }
  }
  t.push_back(pair<int, int>(24 * 3600, 0));
  t.push_back(pair<int, int>(0, 0));

  sort(t.begin(), t.end(), [](const auto &a, const auto &b) {
    if (a.first == b.first)
      return a.second < b.second;
    return a.first < b.first;
  });

  int ans{0};
  for (int i = 0; i < 2 * n + 1; i++) {
    counter += t[i].second;
    if (counter == n) {
      ans += t[i + 1].first - t[i].first;
    }
  }
  cout << ans << endl;
}
