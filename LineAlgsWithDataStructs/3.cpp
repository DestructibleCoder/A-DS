#include <deque>
#include <iostream>

using std::cout, std::cin, std::endl, std::deque;

int main() {
  int n, k;
  cin >> n >> k;

  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  deque<int> d;
  deque<int> res;
  for (int i = 0; i < n; i++) {
    if (i >= k && d.front() == i - k)
      d.pop_front();
    while (d.size() && a[d.back()] >= a[i])
      d.pop_back();
    d.push_back(i);
    if (i >= k - 1)
      res.push_back(d.front());
  }

  while (res.size()) {
    cout << a[res.front()] << endl;
    res.pop_front();
  }
}
