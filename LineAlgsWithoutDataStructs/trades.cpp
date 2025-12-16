#include <iostream>

using std::cout, std::cin, std::endl;

int main() {
  int n, start_capital;
  cin >> n >> start_capital;

  int bd[n]{0};
  for (int i = 0; i < n; i++)
    cin >> bd[i];
  int sd[n]{0};
  for (int i = 0; i < n; i++)
    cin >> sd[i];

  int bbd{0}, bsd{0}, imin{0};
  for (int j = 0; j < n; j++) {
    if (bd[imin] > bd[j])
      imin = j;
    if ((start_capital / bd[bbd]) * sd[bsd] + start_capital % bd[bbd] <
        (start_capital / bd[imin]) * sd[j] + start_capital % bd[imin]) {
      bbd = imin;
      bsd = j;
    }
  }

  if ((double)sd[bsd] / (double)bd[bbd] <= 1)
    cout << start_capital << '\n' << "-1 -1" << endl;
  else
    cout << (start_capital - start_capital % bd[bbd]) / bd[bbd] * sd[bsd] +
                start_capital % bd[bbd]
         << '\n'
         << bbd + 1 << ' ' << bsd + 1 << endl;
}
