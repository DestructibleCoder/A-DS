#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool check(vector<int>, int, int, int, int);

int main() {
  int n, r, c;
  cin >> n >> r >> c;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int L{-1}, R{a.back() - a.front() + 1}, m;
  cout << R << endl;
  while (R - L > 1) {
    m = L + (R - L) / 2;
    if (check(a, m, n, r, c)) {
      R = m;
    } else {
      L = m;
    }
  }
  cout << R << endl;
}

bool check(vector<int> a, int m, int n, int r, int c) {
  int cr = 0;
  int i = 0;
  while (i <= n - c) {
    if (a[i + c - 1] - a[i] <= m) {
      cr++;
      i += c;
    } else
      i++;
  }
  return cr >= r;
}
