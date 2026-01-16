#include <iostream>

using std::cout, std::endl, std::cin;

int main() {
  int x0, y0, x1, y1, x2, y2;
  cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;

  bool isColinear = (x0 - x1) * (y2 - y1) - (y0 - y1) * (x2 - x1) == 0 &&
                    (x0 - x2) * (y1 - y2) - (y0 - y2) * (x1 - x2) == 0;
  bool isCoDirected = (x0 - x2) * (x1 - x2) >= 0 &&
                      (y0 - y2) * (y1 - y2) >= 0 &&
                      (x0 - x1) * (x2 - x1) >= 0 && (y0 - y1) * (y2 - y1) >= 0;

  cout << (isCoDirected && isColinear ? "YES" : "NO") << endl;
}
