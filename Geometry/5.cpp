#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

struct Point {
  int x, y;
} OA, OB;

long getSin(const Point &a, const Point &b) { return a.x * b.y - a.y * b.x; }

long getCos(const Point &a, const Point &b) { return a.x * b.x + a.y * b.y; }

int main() {
  cin >> OA.x >> OA.y >> OB.x >> OB.y;

  cout << fixed << setprecision(5) << abs(atan2(getSin(OA, OB), getCos(OA, OB)))
       << endl;
}
