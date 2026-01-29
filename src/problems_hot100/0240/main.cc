#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();

    int x = 0, y = n - 1;
    while (x < m && y >= 0) {
      if (matrix[x][y] == target)
        return true;
      else if (matrix[x][y] < target)
        ++x;
      else
        --y;
    }
    return false;
  }
};

int main() {
  vector<vector<int>> matrix = {{-5}};
  //   vector<vector<int>> matrix = {{1, 4, 7, 11, 15},
  //                                 {2, 5, 8, 12, 19},
  //                                 {3, 6, 9, 16, 22},
  //                                 {10, 13, 14, 17, 24},
  //                                 {18, 21, 23, 26, 30}};
  int target = 5;
  Solution s;
  cout << s.searchMatrix(matrix, target);
  return 0;
}