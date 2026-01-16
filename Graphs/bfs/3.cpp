#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> bfs(vector<vector<int>> &, vector<int>, int, int);

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> exits(k);
  for (int i = 0; i < k; i++)
    cin >> exits[i];

  int m;
  cin >> m;

  vector<vector<int>> adjList(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int from, to;
    cin >> from >> to;

    adjList[from - 1].push_back(to - 1);
    adjList[to - 1].push_back(from - 1);
  }

  vector<int> ans = bfs(adjList, exits, n, k);
  for (int i = 0; i < n; i++) {
    cout << ans[i] << ' ';
  }
  cout << endl;
}

vector<int> bfs(vector<vector<int>> &adjList, vector<int> exits,
                int countOfNodes, int countOfExits) {
  queue<int> queue;
  vector<int> visited(countOfNodes, 1e9);
  for (int i = 0; i < countOfExits; i++) {
    queue.push(exits[i] - 1);
    visited[exits[i] - 1] = 0;
  }
  while (!queue.empty()) {
    int currentNode = queue.front();
    queue.pop();

    for (int i = 0; i < (int)adjList[currentNode].size(); i++) {
      if (visited[adjList[currentNode][i]] > visited[currentNode] + 1) {
        queue.push(adjList[currentNode][i]);
        visited[adjList[currentNode][i]] = visited[currentNode] + 1;
      }
    }
  }
  return visited;
}
