#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> cur;
    dfs(s, ans, cur, 0);
    return ans;
  }

  bool isPstr(const string &str, int i, int j) {
    while (i < j) {
      if (str[i++] != str[j--])
        return false;
    }
    return true;
  }

  void dfs(const string &s, vector<vector<string>> &ans, vector<string> &cur,
           int i) {
    if (i == s.size()) {
      ans.emplace_back(cur);
      return;
    }

    for (int j = i; j < s.size(); ++j) {
      if (isPstr(s, i, j)) {
        cur.emplace_back(s.substr(i, j - i + 1));
        dfs(s, ans, cur, j + 1);
        cur.pop_back();
      }
    }
  }
};

int main() {
  string s = "aab";
  Solution solution;
  auto ans = solution.partition(s);
  for (auto &vec : ans) {
    for (auto &str : vec)
      cout << '"' << str << '"' << ", ";
    cout << endl;
  }
  return 0;
}