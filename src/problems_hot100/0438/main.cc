#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    int ls = s.size();
    int lp = p.size();
    if (ls < lp)
      return {};
    vector<int> cnt_s(26, 0);
    vector<int> cnt_p(26, 0);

    for (auto &ch : p)
      ++cnt_p[ch - 'a'];

    auto __xx = [&]() -> bool {
      for (int i = 0; i < 26; ++i) {
        if (cnt_p[i] != cnt_s[i])
          return false;
      }
      return true;
    };

    vector<int> rtn;
    int left = 0, right = 0;
    for (; right < left + lp - 1; ++right) {
      ++cnt_s[s[right] - 'a'];
    }
    for (; right < ls; ++right) {
      ++cnt_s[s[right] - 'a'];
      if (__xx()) {
        rtn.emplace_back(left);
      }
      --cnt_s[s[left] - 'a'];
      ++left;
    }
    return rtn;
  }
};

int main() {
  //   string s = "cbaebabacd", p = "abc";
  string s = "abab", p = "ab";
  Solution solution;
  auto rtn = solution.findAnagrams(s, p);
  for (auto &i : rtn)
    cout << i << " ";
  return 0;
}