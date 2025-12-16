#include <iostream>

using std::cout, std::cin, std::endl;

int main() {
  int n;
  cin >> n;

  int a[n][2];
  for (int i = 0; i < n; i++) {
    cin >> a[i][0];
    cin >> a[i][1];
  }
}
