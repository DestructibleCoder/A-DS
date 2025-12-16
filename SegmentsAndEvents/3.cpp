#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> s(2 * n + 1);
  vector<pair<int, int>> p(m);
  for (int i = 0; i < n; i++) {
    cin >> s[2 * i].first >> s[2 * i + 1].first;
    if (s[i * 2].first == s[i * 2 + 1].first) {
      s[2 * i].second = -1;
      s[i * 2 + 1].second = 0;
    } else if (s[2 * i].first <= s[2 * i + 1].first) {
      s[2 * i].second = -1;
      s[2 * i + 1].second = 1;
    } else {
      s[2 * i].second = 1;
      s[2 * i + 1].second = -1;
    }
  }
  for (int i = 0; i < m; i++) {
    cin >> p[i].first;
    p[i].second = i;
  }

  s[n * 2] = pair<int, int>(1000000001, 0);
  sort(s.begin(), s.end());
  sort(p.begin(), p.end());

  int counter = 0;
  int mi = 0;
  while (p[mi].first < s[0].first) {
    p[mi].first = 0;
    mi++;
  }
  for (int i = 0; i < 2 * n; i++) {
    if (mi == m)
      break;
    if (s[i].first == s[i + 1].first && s[i].first == p[mi].first) {
      int countOfClosing{0};
      int closed{0};
      do {
        if (s[i].second == 1 || s[i].second == 0) {
          if (s[i].second == 0)
            closed++;
          countOfClosing++;
        }
        if (s[i].second != 1)
          counter--;
        i++;
      } while (s[i - 1].first == s[i].first);
      i--;
      p[mi].first = -(counter + closed);
      counter += countOfClosing;
      mi++;
      continue;
    } else if (s[i].first >= p[mi].first) {
      if (s[i].first == p[mi].first) {
        if (s[i].second == -1)
          counter--;
        p[mi].first = -counter;
        if (s[i].second == 1)
          counter++;
        mi++;
        continue;
      } else {
        p[mi].first = -counter;
        mi++;
      }
    }
    if (s[i].second == 0)
      counter++;
    counter += s[i].second;
  }
  while (mi != m) {
    p[mi].first = 0;
    mi++;
  }

  sort(p.begin(), p.end(),
       [](const auto &a, const auto &b) { return a.second <= b.second; });

  for (int i = 0; i < m; i++)
    cout << p[i].first << ' ';
  cout << endl;
}
