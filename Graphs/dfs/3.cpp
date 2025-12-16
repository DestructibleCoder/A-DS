#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool check(int, vector<vector<int>> &);

int main() {
  int n;
  cin >> n;

  vector<vector<int>> adjMx(n, vector<int>(n));

  return 0;
}

bool check(int countOfNodes, vector<vector<int>> &adjMx) {
  stack<int> st;

  vector<int> used_glob(countOfNodes);
  vector<int> used_loc(countOfNodes);

  for (int i = 0; i < countOfNodes; i++) {
    if (!used_glob[i]) {
      st.push(i);
      for (int i = 0; i < countOfNodes; i++) {
        int currentNode = st.top();
        st.pop();
      }
    }
  }
  return false;
}
