#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int n;
  cin >> n;

  vector<pair<int, int>> s(2 * n);
  for (int i = 0; i < n; i++) {
    cin >> s[2 * i].first >> s[2 * i + 1].first;
    s[2 * i].second = -1;
    s[2 * i + 1].second = 1;
  }
  sort(s.begin(), s.end());

  int sum = 0;
  int f = -1;
  int start = s[0].first;
  int end = s[0].first;
  for (int i = 1; i < 2 * n; i++) {
    end = s[i].first;
    f += s[i].second;
    if (!f) {
      sum += end - start;
      if (i < 2 * n - 1)
        start = s[i + 1].first;
    }
  }
  cout << sum << endl;
}
