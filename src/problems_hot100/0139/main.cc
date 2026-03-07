#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    vector<bool> dp(s.length() + 1, false);
    unordered_set<string> set(wordDict.begin(), wordDict.end());

    dp[0] = true;
    for (int i = 1; i <= s.length(); ++i) {
      for (int j = 0; j < i; ++j) {
        dp[i] = dp[j] && set.contains(s.substr(j, i - j)); // 0..i-1: (i-1) - j + 1 = i - j
        if (dp[i]) break;
      }
    }
    return dp[s.length()];
  }
};

int main() {
  string s = "applepenapple";
  vector<string> wordDict = {"apple", "pen"};
  Solution solution;
  cout << solution.wordBreak(s, wordDict) << endl;
  return 0;
}