#include <iostream>

using std::cout, std::endl, std::cin;

float countTriangleArea(int x0, int y0, int x1, int y1, int x2, int y2) {
  return abs((x1 - x0) * (y2 - y1) - (y1 - y0) * (x2 - x1)) / 2.0;
}

int main() {
  int x0, y0, x1, y1, x2, y2;
  cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;

  cout << countTriangleArea(x0, y0, x1, y1, x2, y2) << endl;
}
