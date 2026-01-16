#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &adjList, int v, vector<int> &visited, int color) {
  visited[v] = color;
  for (int i : adjList[v]) {
    if (!visited[i])
      dfs(adjList, i, visited, color);
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adjList(n, vector<int>());
  vector<int> visited(n, 0);

  for (int i = 0; i < m; i++) {
    int from, to;

    cin >> from >> to;
    adjList[from - 1].push_back(to - 1);
    adjList[to - 1].push_back(from - 1);
  }

  int counter{0};
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      counter++;
      dfs(adjList, i, visited, counter);
    }
  }

  cout << counter << endl;
  vector<vector<int>> ans(counter);
  for (int i = 0; i < n; i++) {
    ans[visited[i] - 1].push_back(i + 1);
  }
  for (int i = 0; i < counter; i++) {
    cout << ans[i].size() << endl;
    for (int node : ans[i])
      cout << node << ' ';
    cout << endl;
  }
}
