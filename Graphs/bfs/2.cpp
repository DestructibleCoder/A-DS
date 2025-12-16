#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> bfs(vector<vector<int>> &adjList, int countOfNodes, int root);

int main() {
  int n;
  cin >> n;

  vector<vector<int>> ans;

  for (int i = 0; i < n; i++) {
    int countOfNodes, countOfBridges;
    cin >> countOfNodes >> countOfBridges;

    vector<vector<int>> adjList(countOfNodes, vector<int>());
    for (int j = 0; j < countOfBridges; j++) {
      int from, to;
      cin >> from >> to;
      adjList[from].push_back(to);
    }

    int start;
    cin >> start;

    vector<int> to_push = bfs(adjList, countOfNodes, start);
    ans.push_back(to_push);
  }

  for (auto i : ans) {
    for (int j : i) {
      cout << j << ' ';
    }
    cout << endl;
  }
}

vector<int> bfs(vector<vector<int>> &adjList, int countOfNodes, int root) {
  queue<int> queue;
  queue.push(root);

  vector<int> visited(countOfNodes, 987654321);
  visited[root] = -1;

  while (!queue.empty()) {
    int currentNode = queue.front();
    queue.pop();

    visited[currentNode] += 1;

    for (int i : adjList[currentNode]) {
      if (visited[i] == 987654321) {
        queue.push(i);
        visited[i] = visited[currentNode];
      }
    }
  }

  return visited;
}
