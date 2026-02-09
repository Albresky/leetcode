#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  int time = 0;
  int fresh = 0;
  vector<vector<int>> DIRECTION = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
  int M, N;
  bool valid(int x, int y) { return 0 <= x && x < M && 0 <= y && y < N; }

public:
  int orangesRotting(vector<vector<int>> &grid) {
    M = grid.size();
    N = grid[0].size();
    vector<pair<int, int>> rotpos;
    for (int m = 0; m < M; ++m) {
      for (int n = 0; n < N; ++n) {
        if (grid[m][n] == 2) {
          rotpos.emplace_back(pair(m, n));
        } else if (grid[m][n] == 1)
          ++fresh;
      }
    }
    while (fresh && !rotpos.empty()) {
      ++time;
      vector<pair<int, int>> rotpos_next;

      for (auto &[x, y] : rotpos) {
        for (auto &d : DIRECTION) {
          auto nextx = x + d[0];
          auto nexty = y + d[1];
          if (valid(nextx, nexty)) {
            if (grid[nextx][nexty] == 1) {
              --fresh;
              grid[nextx][nexty] = 2;
              rotpos_next.emplace_back(pair(nextx, nexty));
            }
          }
        }
      }
      rotpos = std::move(rotpos_next);
    }
    return fresh > 0 ? -1 : time;
  }
};

int main() {
  vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
  Solution s;
  cout << s.orangesRotting(grid) << endl;
  return 0;
}