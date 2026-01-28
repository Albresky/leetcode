#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    bool r0 = false, c0 = false;

    for (int j = 0; j < n; ++j) {
      if (matrix[0][j] == 0) {
        r0 = true;
        break;
      }
    }
    for (int i = 0; i < m; ++i) {
      if (matrix[i][0] == 0) {
        c0 = true;
        break;
      }
    }
    for (int x = 1; x < m; ++x) {
      for (int y = 1; y < n; ++y) {
        if (matrix[x][y] == 0) {
          matrix[0][y] = 0;
          matrix[x][0] = 0;
        }
      }
    }

    for (int x = 1; x < m; ++x) {
      for (int y = 1; y < n; ++y) {
        if (matrix[x][0] == 0 || matrix[0][y] == 0) {
          matrix[x][y] = 0;
        }
      }
    }
    if (r0) {
      for (auto &num : matrix[0])
        num = 0;
    }
    if (c0) {
      for (int r = 0; r < m; ++r)
        matrix[r][0] = 0;
    }
  }
};

int main() {
  //   vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
  Solution s;
  s.setZeroes(matrix);
  for (auto &row : matrix) {
    for (auto num : row)
      cout << num << " ";
    cout << endl;
  }
}