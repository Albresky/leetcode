#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<string>> solveNQueens(int n) {
    vector<bool> col(n, false);
    vector<bool> diag1(2 * n - 1, false);
    vector<bool> diag2(2 * n - 1, false);
    vector<vector<string>> ans;
    vector<string> cur;
    dfs(n, ans, cur, col, diag1, diag2, 0);
    return ans;
  }

  void dfs(const int n, vector<vector<string>> &ans, vector<string> &cur,
           vector<bool> &col, vector<bool> &diag1, vector<bool> &diag2,
           int row) {
    if (row == n) {
      ans.emplace_back(cur);
      return;
    }
    for (int c = 0; c < n; ++c) {
      if (col[c])
        continue;
      if (diag1[row - c + n - 1])
        continue;
      if (diag2[row + c])
        continue;
      string strRow(n, '.');

      col[c] = true;
      diag1[row - c + n - 1] = true;
      diag2[row + c] = true;
      strRow[c] = 'Q';
      cur.push_back(strRow);
      dfs(n, ans, cur, col, diag1, diag2, row + 1);
      cur.pop_back();
      col[c] = false;
      diag1[row - c + n - 1] = false;
      diag2[row + c] = false;
    }
  }
};

int main() {
  int n = 4;
  Solution s;
  auto ans = s.solveNQueens(n);
  int cnt = 0;
  for (auto &vec : ans) {
    cout << "\n" << ++cnt << endl;
    for (auto &str : vec)
      cout << str << endl;
  }
  return 0;
}