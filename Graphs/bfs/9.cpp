#include <deque>
#include <iostream>
#include <vector>

#define adjVector vector<vector<pair<int, int>>>

using namespace std;

int bfs(const adjVector &adjList, const pair<int, int> &path, int countOfNodes);

int main() {
  int countOfNodes, countOfBridges;
  cin >> countOfNodes >> countOfBridges;

  adjVector adjList(countOfNodes, vector<pair<int, int>>());
  for (int i = 0; i < countOfBridges; i++) {
    int from, to;
    cin >> from >> to;

    adjList[from - 1].emplace_back(to - 1, 0);
    if (from != to)
      adjList[to - 1].emplace_back(from - 1, 1);
  }

  int countOfPaths;
  cin >> countOfPaths;

  vector<pair<int, int>> paths;
  for (int i = 0; i < countOfPaths; i++) {
    int from, to;
    cin >> from >> to;

    paths.emplace_back(from - 1, to - 1);
  }

  for (int i = 0; i < countOfPaths; i++) {
    cout << bfs(adjList, paths[i], countOfNodes) << endl;
  }
}

int bfs(const adjVector &adjList, const pair<int, int> &path,
        int countOfNodes) {
  auto [from, to] = path;

  deque<int> deq;
  deq.push_back(from);

  vector<int> visited(countOfNodes, 1e9);
  visited[from] = 0;

  while (!deq.empty()) {
    int currentNode = deq.front();
    deq.pop_front();

    for (auto [dest, cost] : adjList[currentNode]) {
      if (visited[currentNode] + cost < visited[dest]) {
        visited[dest] = visited[currentNode] + cost;
        if (cost) {
          deq.push_back(dest);
        } else {
          deq.push_front(dest);
        }
      }
    }
  }

  return visited[to] == 1e9 ? -1 : visited[to];
}
