#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    vector<string> map = {"",    "",    "abc",  "def", "ghi",
                          "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> ans;
    string comb;
    dfs(digits, map, ans, comb, 0);
    return ans;
  }

  void dfs(const string &digits, const vector<string> &map, vector<string> &ans,
           string &comb, int idx) {
    if (idx == digits.length()) {
      ans.emplace_back(comb);
    } else {
      int num = digits[idx] - '0';
      for (auto &ch : map[num]) {
        comb.push_back(ch);
        dfs(digits, map, ans, comb, idx + 1);
        comb.pop_back();
      }
    }
  }
};

int main() {
  string digits = "23";
  Solution s;
  auto rtn = s.letterCombinations(digits);
  for (auto ch : rtn)
    cout << ch << " ";
  cout << endl;
  return 0;
}