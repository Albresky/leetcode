#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> ans;
    string cur = "";
    dfs(ans, cur, 0, 0, n);
    return ans;
  }

  void dfs(vector<string> &ans, string &cur, int l, int r, int n) {
    if (cur.length() == n * 2) {
      ans.emplace_back(cur);
      return;
    }

    if (l < n) {
      cur += '(';
      dfs(ans, cur, l + 1, r, n);
      cur.pop_back();
    }
    if (r < l) {
      cur += ')';
      dfs(ans, cur, l, r + 1, n);
      cur.pop_back();
    }
  }
};

int main() {
  int n = 3;
  Solution s;
  auto ans = s.generateParenthesis(n);
  for (auto &str : ans)
    cout << '"' << str << '"' << ", ";
  cout << endl;
  return 0;
}