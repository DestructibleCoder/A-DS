#include <iostream>

using std::cout, std::cin, std::endl;

int main() {
  int n;
  cin >> n;

  int nums[n]{0};
  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  int sums[n + 1]{0};
  for (int i = 1; i <= n; i++) {
    sums[i] = sums[i - 1] + nums[i - 1];
  }

  int i{0}, ibest{0}, jbest{1};
  for (int j = 1; j <= n; j++) {
    if (sums[j] - sums[i] > sums[jbest] - sums[ibest]) {
      ibest = i;
      jbest = j;
    }
    if (sums[j] <= sums[i])
      i = j;
  }

  cout << ibest + 1 << '\n' << jbest << endl;
}
