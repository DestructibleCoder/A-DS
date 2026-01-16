#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void bfs(vector<vector<int>> &, int, int);

int main() {
  int rowLength, colLength;
  cin >> colLength >> rowLength;

  vector<vector<int>> table(colLength, vector<int>(rowLength, 0));
  for (int i = 0; i < colLength; i++) {
    for (int j = 0; j < rowLength; j++) {
      cin >> table[i][j];
    }
  }

  bfs(table, colLength, rowLength);
  for (int i = 0; i < colLength; i++) {
    for (int j = 0; j < rowLength; j++)
      cout << table[i][j] << ' ';
    cout << endl;
  }
}

void bfs(vector<vector<int>> &table, int colLength, int rowLength) {
  queue<pair<int, int>> queue;

  for (int i = 0; i < colLength; i++) {
    for (int j = 0; j < rowLength; j++) {
      if (table[i][j] == 1) {
        table[i][j] = 0;
        queue.push(pair<int, int>(i, j));
      } else {
        table[i][j] = 1e9;
      }
    }
  }

  while (!queue.empty()) {
    pair<int, int> currentNode = queue.front();
    queue.pop();

    /*if (currentNode.first > 0 && currentNode.second > 0 &&
        table[currentNode.first - 1][currentNode.second - 1] >
            table[currentNode.first][currentNode.second] + 1) {
      table[currentNode.first - 1][currentNode.second - 1] =
          table[currentNode.first][currentNode.second] + 1;
      queue.push(pair<int, int>(currentNode.first - 1, currentNode.second - 1));
    }
    if (currentNode.first > 0 && currentNode.second + 1 < rowLength &&
        table[currentNode.first - 1][currentNode.second + 1] >
            table[currentNode.first][currentNode.second] + 1) {
      table[currentNode.first - 1][currentNode.second + 1] =
          table[currentNode.first][currentNode.second] + 1;
      queue.push(pair<int, int>(currentNode.first - 1, currentNode.second + 1));
    }
    if (currentNode.first + 1 < colLength && currentNode.second > 0 &&
        table[currentNode.first + 1][currentNode.second - 1] >
            table[currentNode.first][currentNode.second] + 1) {
      table[currentNode.first + 1][currentNode.second - 1] =
          table[currentNode.first][currentNode.second] + 1;
      queue.push(pair<int, int>(currentNode.first + 1, currentNode.second - 1));
    } */
    // if (currentNode.first + 1 < colLength &&
    //     currentNode.second + 1 < rowLength &&
    //     table[currentNode.first + 1][currentNode.second + 1] >
    //         table[currentNode.first][currentNode.second] + 1) {
    //   table[currentNode.first + 1][currentNode.second + 1] =
    //       table[currentNode.first][currentNode.second] + 1;
    //   queue.push(pair<int, int>(currentNode.first + 1, currentNode.second +
    //   1));
    // }
    if (currentNode.first > 0 &&
        table[currentNode.first - 1][currentNode.second] >
            table[currentNode.first][currentNode.second] + 1) {
      table[currentNode.first - 1][currentNode.second] =
          table[currentNode.first][currentNode.second] + 1;
      queue.push(pair<int, int>(currentNode.first - 1, currentNode.second));
    }
    if (currentNode.first + 1 < colLength &&
        table[currentNode.first + 1][currentNode.second] >
            table[currentNode.first][currentNode.second] + 1) {
      table[currentNode.first + 1][currentNode.second] =
          table[currentNode.first][currentNode.second] + 1;
      queue.push(pair<int, int>(currentNode.first + 1, currentNode.second));
    }
    if (currentNode.second > 0 &&
        table[currentNode.first][currentNode.second - 1] >
            table[currentNode.first][currentNode.second] + 1) {
      table[currentNode.first][currentNode.second - 1] =
          table[currentNode.first][currentNode.second] + 1;
      queue.push(pair<int, int>(currentNode.first, currentNode.second - 1));
    }
    if (currentNode.second + 1 < rowLength &&
        table[currentNode.first][currentNode.second + 1] >
            table[currentNode.first][currentNode.second] + 1) {
      table[currentNode.first][currentNode.second + 1] =
          table[currentNode.first][currentNode.second] + 1;
      queue.push(pair<int, int>(currentNode.first, currentNode.second + 1));
    }
  }
}
