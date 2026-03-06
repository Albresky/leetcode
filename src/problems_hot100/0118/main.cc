#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;

    for (int i = 0; i < numRows; ++i) {

      vector<int> cur(i + 1, 1);

      for (int j = 1; j < i; ++j) {
        cur[j] = ans[i - 1][j - 1] + ans[i - 1][j];
      }
      ans.emplace_back(cur);
    }
    return ans;
  }
};

int main() {
  int numRows = 30;
  Solution s;
  auto ret = s.generate(numRows);
  for (auto &vec : ret) {
    for (auto n : vec) printf("%-6d", n);
    cout << endl;
  }
  return 0;
}