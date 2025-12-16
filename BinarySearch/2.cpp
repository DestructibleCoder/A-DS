#include <algorithm>
#include <iostream>

using namespace std;

bool check(long long, long long, long long, long long);

int main(void) {
  long long h, w, n;
  cin >> w >> h >> n;
  long long L{0}, R{max(w, h) * n}, m;
  while (R - L > 1) {
    m = L + (R - L) / 2;
    if (check(h, w, n, m)) {
      R = m;
    } else {
      L = m;
    }
  }
  cout << R << endl;
}

bool check(long long h, long long w, long long n, long long m) {
  return (m / h) * (m / w) >= n;
}
