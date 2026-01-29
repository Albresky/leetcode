#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();
    if (n == 1)
      return;

    // transpose
    for (int x = 0; x < n; ++x) {
      for (int y = 0; y < x; ++y) {
        swap(matrix[x][y], matrix[y][x]);
      }
    }

    // flip horizontally
    for (int x = 0; x < n; ++x) {
      for (int i = 0; i < n / 2; ++i) {
        swap(matrix[x][i], matrix[x][n - 1 - i]);
      }
    }
  }
};

int main() {
  vector<vector<int>> matrix = {
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
  Solution s;
  s.rotate(matrix);
  for (auto &row : matrix) {
    for (auto &num : row)
      cout << num << " ";
    cout << "\n";
  }
  return 0;
}