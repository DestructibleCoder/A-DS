#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct time_segment {
  int first;
  int second;
  int index;

  time_segment(int first = 0, int second = 0, int index = 0) {
    this->first = first;
    this->second = second;
    this->index = index;
  }
};

int main(void) {
  int n;
  cin >> n;
  vector<time_segment> time(n + 1);

  for (int i = 0; i < n; i++) {
    cin >> time[i].first;
    cin >> time[i].second;
    time[i].index = i + 1;
  }
  time[n] = time_segment(0, 0, 0);
  sort(time.begin(), time.end(),
       [](const auto &a, const auto &b) { return a.second < b.second; });

  int last_f = 0;
  for (int i = 1; i < n + 1; i++) {
    if (time[i].first >= time[last_f].second) {
      last_f = i;
      cout << time[i].index << ' ';
    }
  }
  cout << endl;
}
