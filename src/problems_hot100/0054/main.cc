#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    if (m == 1)
      return matrix[0];

    vector<int> rtn;
    // r,d,l,u
    int r = n, d = m - 1, l = n - 1, u = m - 2;
    int DIRECTION = 0;
    for (int steps = 0, x = 0, y = -1; steps < m * n;) {
      switch (DIRECTION) {
      case 0:
        for (int step = 0; step < r; ++step) {
          rtn.emplace_back(matrix[x][++y]);
        }
        steps += r;
        r -= 2;
        break;
      case 1:
        for (int step = 0; step < d; ++step)
          rtn.emplace_back(matrix[++x][y]);
        steps += d;
        d -= 2;
        break;
      case 2:
        for (int step = 0; step < l; ++step)
          rtn.emplace_back(matrix[x][--y]);
        steps += l;
        l -= 2;
        break;
      case 3:
        for (int step = 0; step < u; ++step)
          rtn.emplace_back(matrix[--x][y]);
        steps += u;
        u -= 2;
        break;
      default:
        break;
      }
      (++DIRECTION) %= 4;
    }
    return rtn;
  }
};

int main() {
  //   vector<vector<int>> matrix = {{1, 2, 3}, {8, 9, 4}, {7, 6, 5}};
  vector<vector<int>> matrix = {{1, 2, 3, 4}, {10, 11, 12, 5}, {9, 8, 7, 6}};
  Solution s;
  auto rtn = s.spiralOrder(matrix);
  for (auto &num : rtn)
    cout << num << " ";
  return 0;
}