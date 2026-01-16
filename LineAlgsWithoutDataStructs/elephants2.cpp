#include <iostream>

using std::cout, std::cin, std::endl;

int main() {
  int n;
  cin >> n;

  int arr[n]{};
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int fd{0}, ld{1}, min{0};

  for (int i = 2; i < n; i++) {
    if (arr[min] > arr[i - 1])
      min = i - 1;
    if ((double)arr[ld] / (double)arr[fd] < (double)arr[i] / (double)arr[min]) {
      fd = min;
      ld = i;
    }
  }

  if (arr[ld] - arr[fd])
    cout << fd + 1 << ' ' << ld + 1 << endl;
  else
    cout << "0 0" << endl;
}
