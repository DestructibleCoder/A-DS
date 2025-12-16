#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int moves[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1},
                         {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};

void solve(int size, int x1, int y1, int x2, int y2) {
  x1--;
  x2--;
  y1--;
  y2--;

  vector<vector<vector<int>>> chessDeck(
      size, vector<vector<int>>(size, vector<int>(3, 1e9)));

  queue<pair<int, int>> que;
  que.emplace(x1, y1);
  chessDeck[x1][y1] = {0, -1, -1};
  while (!que.empty()) {
    auto [x, y] = que.front();
    que.pop();

    if (x == x2 && y == y2) {
      break;
    }

    for (const auto &move : moves) {
      int mtx = x + move[0];
      int mty = y + move[1];

      if (mtx >= 0 && mty >= 0 && mtx < size && mty < size &&
          chessDeck[mtx][mty][0] == 1e9) {
        chessDeck[mtx][mty] = {chessDeck[x][y][0] + 1, x, y};
        que.emplace(mtx, mty);
      }
    }
  }

  cout << chessDeck[x2][y2][0] << endl;

  vector<pair<int, int>> path;
  int curX = x2, curY = y2;

  while (curX != -1) {
    path.push_back({curX, curY});
    int parentX = chessDeck[curX][curY][1];
    int parentY = chessDeck[curX][curY][2];
    curX = parentX;
    curY = parentY;
  }

  reverse(path.begin(), path.end());

  for (const auto &p : path) {
    cout << p.first + 1 << ' ' << p.second + 1 << endl;
  }
}

int main() {
  int n, x1, y1, x2, y2;
  cin >> n >> x1 >> y1 >> x2 >> y2;

  solve(n, x1, y1, x2, y2);
  return 0;
}
