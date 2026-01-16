#include <iostream>
#include <vector>

using namespace std;

int counter{0};

void gen(int, int, vector<int> &, vector<int> &, vector<int> &);

int main(void) {
  int n;
  cin >> n;
  vector<int> jt(n, 0);
  vector<int> du(2 * n - 1, 0);
  vector<int> dd(2 * n - 1, 0);
  gen(0, n, jt, du, dd);
  cout << counter << endl;
}

void gen(int i, int n, vector<int> &jt, vector<int> &du, vector<int> &dd) {
  if (i == n) {
    counter++;
    return;
  }
  for (int j = 0; j < n; j++) {
    if (jt[j] || du[j - i + n - 1] || dd[i + j])
      continue;
    jt[j] = 1;
    du[j - i + n - 1] = 1;
    dd[i + j] = 1;
    gen(i + 1, n, jt, du, dd);
    jt[j] = 0;
    du[j - i + n - 1] = 0;
    dd[i + j] = 0;
  }
}
