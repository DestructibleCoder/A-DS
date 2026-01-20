#include <iostream>

using namespace std;

struct Point {
  int x, y;
} A, B;

int main() {
  cin >> A.x >> A.y >> B.x >> B.y;

  cout << A.y - B.y << ' ' << B.x - A.x << ' ' << A.x * B.y - B.x * A.y << endl;
}
