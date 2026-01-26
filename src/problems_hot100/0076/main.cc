#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  string minWindow(string s, string t) {
    vector<int> cnt_s(128, 0);
    vector<int> cnt_t(128, 0);
    for (auto ch : t)
      ++cnt_t[ch];

    auto _covered = [&]() -> bool {
      for (char ch = 'A'; ch <= 'Z'; ++ch) {
        if (cnt_t[ch] > cnt_s[ch])
          return false;
      }
      for (char ch = 'a'; ch <= 'z'; ++ch) {
        if (cnt_t[ch] > cnt_s[ch])
          return false;
      }
      return true;
    };

    int len = s.size();
    int left = 0;
    int rtn_left = -1, rtn_right = len;
    for (int right = 0; right < len; ++right) {
      ++cnt_s[s[right]];
      while (_covered()) {
        if (right - left < rtn_right - rtn_left) {
          rtn_left = left;
          rtn_right = right;
        }
        --cnt_s[s[left]];
        ++left;
      }
    }

    return rtn_left < 0 ? "" : s.substr(rtn_left, rtn_right - rtn_left + 1);
  }
};

int main() {
  //   string s = "ADOBECODEBANC", t = "ABC";
  //   string s = "a", t = "aa";
  string s = "cgklivwehljxrdzpfdqsapogwvjtvbzahjnsejwnuhmomlfsrvmrnczjzjevkdvro"
             "iluthhpqtffhlzyglrvorgnalk",
         t = "mqfff";

  Solution solution;
  auto rtn = solution.minWindow(s, t);
  cout << rtn << endl;
  return 0;
}