#include <iostream>

using namespace std;

int *max(int *start, int *end) {
  int *max_n = start;
  for (; end != start; end--)
    if (*end > *max_n)
      max_n = end;
  return max_n;
}

int main() {
  int n;
  cin >> n;

  int arr[n] = {0};
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int fd, ld;
  int *max_ben{0};

  for (int i = 0; i < n; i++) {
    int *max_n = max(&arr[i], &arr[n - 1]);
    if (max_n - arr[i] > max_ben) {
      max_ben = max_n - arr[i];
      fd = i + 1;
      ld = max_n - arr + 1;
    }
  }

  if (max_ben)
    cout << fd << ' ' << ld << endl;
  else
    cout << "0 0" << endl;
}
