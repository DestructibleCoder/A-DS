#include <iostream>

using namespace std;

struct Point {
  int x, y;
};

long long cross(const Point &a, const Point &b) {
  return 1LL * a.x * b.y - 1LL * b.x * a.y;
}

Point vec(const Point &from, const Point &to) {
  return {to.x - from.x, to.y - from.y};
}

int main() {
  Point A, O, B, P;
  cin >> A.x >> A.y >> O.x >> O.y >> B.x >> B.y >> P.x >> P.y;

  Point OA = vec(O, A);
  Point OB = vec(O, B);
  Point OP = vec(O, P);

  long long ab = cross(OA, OB);
  long long ap = cross(OA, OP);
  long long pb = cross(OP, OB);

  bool isInside;
  if (ab > 0)
    isInside = (ap >= 0 && pb >= 0);
  else
    isInside = (ap <= 0 && pb <= 0);

  cout << (isInside ? "YES" : "NO") << endl;
}
