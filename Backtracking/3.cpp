#include <iostream>
#include <vector>

using namespace std;

void gen(int, int &, int &, vector<int> &, bool);

int main() {
  int k, n;
  cin >> n >> k;

  vector<int> ans(k, 0);
  gen(0, k, n, ans, true);
}

void gen(int i, int &k, int &n, vector<int> &ans, bool isFirst) {
  if (i == k) {
    for (int x = 0; x < k; x++)
      cout << ans[x] << ' ';
    cout << endl;
    return;
  }

  if (isFirst) {
    for (int j = k; j <= n; j++) {
      ans[i] = j;
      gen(i + 1, k, n, ans, false);
    }
  } else {
    for (int j = k - i; j < ans[i - 1]; j++) {
      ans[i] = j;
      gen(i + 1, k, n, ans, false);
    }
  }
}
