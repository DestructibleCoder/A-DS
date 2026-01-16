#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool check(vector<int>, int, int, int);
long long sum(vector<int>);

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  if ((double)sum(a) / (double)k < 1) {
    cout << 0 << endl;
    return 0;
  }
  int L{0}, R{*max_element(a.begin(), a.end()) + 1}, m;
  while (R - L > 1) {
    m = L + (R - L) / 2;
    if (check(a, k, m, n)) {
      R = m;
    } else {
      L = m;
    }
  }
  cout << R - 1 << endl;
}

long long sum(vector<int> a) {
  long long sum = 0;
  for (auto i = a.begin(); i < a.end(); i++)
    sum += *i;
  return sum;
}

bool check(vector<int> a, int k, int m, int n) {
  int km = 0;
  for (int i = 0; i < n; i++) {
    km += a[i] / m;
  }
  return km < k;
}
