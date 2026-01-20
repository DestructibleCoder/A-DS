#include <cmath>
#include <iostream>

using namespace std;

struct Point {
  int x, y;
};

Point vec(const Point &from, const Point &to) {
  return {to.x - from.x, to.y - from.y};
}

long long getSin(const Point &a, const Point &b) {
  return a.x * b.y - a.y * b.x;
}

int main() {
  Point A, B, C;
  cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y;

  Point BA = vec(B, A), BC = vec(B, C);

  if (getSin(BA, BC) == 0)
    cout << "BOTH" << endl;
  else if (getSin(BA, BC) > 0)
    cout << "RIGHT" << endl;
  else
    cout << "LEFT" << endl;
}
