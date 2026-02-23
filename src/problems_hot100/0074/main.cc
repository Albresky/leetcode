#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int M = matrix.size();
    int N = matrix[0].size();
    for (int m = 0, n = N - 1; m < M && n >= 0;) {
      if (target == matrix[m][n])
        return true;
      if (target < matrix[m][n])
        --n;
      else
        ++m;
    }
    return false;
  }
};

int main() {
  vector<vector<int>> matrix = {
      {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
  int target = 3;
  Solution s;
  cout << s.searchMatrix(matrix, target);
  return 0;
}