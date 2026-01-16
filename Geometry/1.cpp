#include <iostream>

int main() {
  int x0, y0, x1, y1, x2, y2;
  std::cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;

  bool isCollinear = (x0 - x1) * (y2 - y1) - (y0 - y1) * (x2 - x1) == 0;
  bool isCoDirected = (x2 - x1) * (x0 - x1) >= 0 && (y2 - y1) * (y0 - y1) >= 0;

  std::cout << (isCoDirected && isCollinear ? "YES" : "NO") << std::endl;
}
