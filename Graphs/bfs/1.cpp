#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int bfs(vector<vector<int>> &, int, int, int);

int main() {
  int n;
  cin >> n;

  vector<vector<int>> p(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> p[i][j];
    }
  }

  int from, to;
  cin >> from >> to;

  int ans = bfs(p, n, from - 1, to - 1);
  cout << ans << endl;
}

int bfs(vector<vector<int>> &pt, int countOfNodes, int root, int searchable) {
  if (root == searchable)
    return 0;
  queue<int> queue;
  queue.push(root);

  vector<int> visited(countOfNodes, 0);

  while (!queue.empty()) {
    int currentNode = queue.front();
    queue.pop();

    visited[currentNode] += 1;

    if (pt[currentNode][searchable])
      return visited[currentNode];

    for (int i = 0; i < countOfNodes; i++) {
      if (pt[i][currentNode] && !visited[i]) {
        queue.push(i);
        visited[i] = visited[currentNode];
      }
    }
  }
  return -1;
}
