#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int moves[8][2]{{2, 1}, {2, -1}, {-2, 1}, {-2, -1},
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

    if (x == x2 && y == y2)
      break;

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

  vector<pair<int, int>> stack;
  while (x2 != -1) {
    stack.emplace_back(chessDeck[x2][y2][1], chessDeck[x2][y2][2]);
    int tmpX = chessDeck[x2][y2][1], tmpY = chessDeck[x2][y2][2];
    x2 = tmpX;
    y2 = tmpY;
  }

  for (int i = (int)stack.size() - 1; i >= 0; i--)
    cout << stack[i].first + 1 << ' ' << stack[i].second + 1 << endl;
}

int main() {
  int n, x1, y1, x2, y2;
  cin >> n >> x1 >> y1 >> x2 >> y2;

  solve(n, x1, y1, x2, y2);
}
