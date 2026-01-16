#include <algorithm>
#include <iostream>

using namespace std;

bool check(int, int, int, int);

int main(void) {
  int m, N, x, y;
  cin >> N >> x >> y;
  int L{-1}, R{min(x, y) * N};
  while (R - L > 1) {
    m = L + (R - L) / 2;
    if (check(m, x, y, N)) {
      R = m;
    } else {
      L = m;
    }
  }
  cout << (N != 1 ? R + min(x, y) : min(x, y)) << endl;
}

bool check(int m, int x, int y, int N) { return (N - 1) <= (m / x + m / y); }
