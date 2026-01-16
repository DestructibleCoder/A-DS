#include <iostream>
#include <vector>

using namespace std;

void gen(int, int, int, vector<int> &);

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> ans;
  gen(0, n, k, ans);
}

void gen(int i, int n, int k, vector<int> &ans) {
  if (i == n) {
    for (int x = 0; x < n; x++)
      cout << ans[x];
    cout << endl;
    return;
  }
  for (int j = 0; j < k; j++) {
    ans.push_back(j);
    gen(i + 1, n, k, ans);
    ans.pop_back();
  }
  return;
}
