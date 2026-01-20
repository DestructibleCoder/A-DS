#include <iostream>
#include <vector>

using namespace std;

void dfs();

int main() {
  int N, M;
  cin >> N >> M;

  vector<vector<int>> adjList(N, vector<int>());
  for (int i = 0; i < M; i++) {
    int from, to;
    cin >> from >> to;

    adjList[from - 1].push_back(to - 1);
  }

  vector<int> visited(N);
  bool flag = false;
  for (int i = 0; i < N; i++) {
    if (visited[i] == 0) {
      dfs();
    }
  }
}

void dfs() { return; }
