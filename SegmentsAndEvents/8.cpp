#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct min_intersection {
  int i, j, size;

  min_intersection(int i = 0, int j = 0, int size = 0) {
    this->i = i;
    this->j = j;
    this->size = size;
  }
};

struct element {
  int first, second, index;

  element(int first = 0, int second = 0, int index = 0) {
    this->first = first;
    this->second = second;
    this->index = index;
  }
};

int main() {
  int n;
  cin >> n;

  vector<element> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i].first >> p[i].second;
    p[i].index = i;
  }

  sort(p.begin(), p.end(),
       [](const auto &a, const auto &b) { return a.first < b.first; });

  min_intersection min_i(0, 0, 2000000001);
  for (int i = 0; i < n; i++) {
  }

  if (min_i.size == 2000000001)
    cout << 0 << endl;
  else
    cout << min_i.i + 1 << ' ' << min_i.j + 1 << endl;
}
