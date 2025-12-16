#include <iostream>

using namespace std;

bool check(__int128_t, __int128_t, __int128_t, __int128_t, __int128_t,
           __int128_t);

int main() {
  long long al, kl, bl, ml, xl;
  cin >> al >> kl >> bl >> ml >> xl;
  __int128_t a{static_cast<__int128_t>(al)}, k{static_cast<__int128_t>(kl)},
      b{static_cast<__int128_t>(bl)}, m{static_cast<__int128_t>(ml)},
      x{static_cast<__int128_t>(xl)};
  __int128_t L{-1}, R{(x / (a + b) + 1) * 2}, mid;
  while (R - L > 1) {
    mid = L + (R - L) / 2;
    if (check(mid, a, k, b, m, x)) {
      R = mid;
    } else {
      L = mid;
    }
  }
  cout << (long long)R << endl;
  return 0;
}

bool check(__int128_t mid, __int128_t a, __int128_t k, __int128_t b,
           __int128_t m, __int128_t x) {
  return (a + b) * mid - mid / k * a - mid / m * b >= x;
}
