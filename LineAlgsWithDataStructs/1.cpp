#include <iostream>
#include <stack>

using std::cout, std::cin, std::endl;

int main() {
  int n;
  cin >> n;
  int a[n]{0};
  int ans[n]{0};

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  std::stack<int> stack;
  for (int i = 0; i < n; i++) {
    while (!stack.empty() && a[i] < a[stack.top()]) {
      ans[stack.top()] = i;
      stack.pop();
    }
    stack.push(i);
  }
  while (!stack.empty()) {
    ans[stack.top()] = -1;
    stack.pop();
  }
  for (int i = 0; i < n; i++)
    cout << ans[i] << ' ';
  cout << endl;
}
