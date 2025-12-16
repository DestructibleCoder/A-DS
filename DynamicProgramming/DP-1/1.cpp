#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n + 2);
  for (int i = 2; i < n + 2; i++) {
    cin >> a[i];
  }
  for (int i = 2; i < n + 2; i++) {
    a[i] += min(a[i - 1], a[i - 2]);
  }
  cout << a[n + 1] << endl;
}
