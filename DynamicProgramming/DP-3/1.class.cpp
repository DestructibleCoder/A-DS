#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class pin {
public:
  int dist;
  bool next_link{false};
  pin() { dist = 0; };
  pin(int dist) { this->dist = dist; }
  int operator-(const pin a) const { return a.dist - this->dist; }
};

int solve(int, vector<pin>);

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  sort(x.begin(), x.end());
  vector<pin> a(n);
  for (int i = 0; i < n; i++) {
    a[i] = pin(x[i]);
  }

  cout << solve(n, a) << endl;
}

int solve(int n, vector<pin> a) {
  int sum = 0;
  for (int i = 0; i < n - 2; i++) {
    if (i == 0) {
      sum += a[i + 1] - a[i - 1];
      continue;
    } else if ((a[i + 1].dist - a[i].dist <= a[i + 2].dist - a[i + 1].dist) &&
               !a[i].next_link) {
      sum += a[i + 1].dist - a[i].dist;
      a[i].next_link = true;
    } else {
      sum += a[i + 2].dist - a[i + 1].dist;
      a[i + 1].next_link = true;
    }
  }
  if (!a[n - 2].next_link) {
    sum += a[n - 1].dist - a[n - 2].dist;
  }
  return sum;
}
