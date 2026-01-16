#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> a(n + 2, vector<int>(m + 2, 0));
  a[2][2] = 1;
  for (int i = 2; i < n + 2; i++) {
    for (int j = 2; j < m + 2; j++) {
      a[i][j] += a[i - 2][j - 1] + a[i - 1][j - 2];
    }
  }
  cout << a[n + 1][m + 1] << endl;
}
