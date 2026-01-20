#include <algorithm>
#include <iostream>

using namespace std;

struct Point {
  long long x, y;
} A, B, C, D;

long long cross(const Point &A, const Point &B, const Point &C) {
  return (B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y);
}

bool onSegment(const Point &A, const Point &B, const Point &C) {
  return min(A.x, B.x) <= C.x && C.x <= max(A.x, B.x) && min(A.y, B.y) <= C.y &&
         C.y <= max(A.y, B.y);
}

int main() {
  cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;

  if ((cross(A, B, C) > 0 && cross(A, B, D) < 0 ||
       cross(A, B, C) < 0 && cross(A, B, D) > 0) &&
      (cross(C, D, A) > 0 && cross(C, D, B) < 0 ||
       cross(C, D, A) < 0 && cross(C, D, B) > 0)) {
    cout << "YES" << endl;
  } else {
    if (cross(A, B, C) == 0 && onSegment(A, B, C)) {
      cout << "YES" << endl;
      return 0;
    }
    if (cross(A, B, D) == 0 && onSegment(A, B, D)) {
      cout << "YES" << endl;
      return 0;
    }
    if (cross(C, D, A) == 0 && onSegment(C, D, A)) {
      cout << "YES" << endl;
      return 0;
    }
    if (cross(C, D, B) == 0 && onSegment(C, D, B)) {
      cout << "YES" << endl;
      return 0;
    }

    cout << "NO" << endl;
    return 0;
  }
}
