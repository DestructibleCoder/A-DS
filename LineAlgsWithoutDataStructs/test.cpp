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

  for (int i : bd)
    cout << i;
  cout << endl;

  for (int i : sd)
    cout << i;
  cout << endl;
}
