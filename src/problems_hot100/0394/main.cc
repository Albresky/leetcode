#include <cctype>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  string decodeString(string s) {
    stack<pair<int, string>> st;
    string ptn;
    int times = 0;
    for (auto ch : s) {
      if (isalpha(ch))
        ptn += ch;
      else if (isdigit(ch))
        times = times * 10 + (ch - '0');
      else if (ch == '[') {
        st.emplace(times, move(ptn));
        times = 0;
      } else if (ch == ']') {
        auto [t, p] = st.top();
        st.pop();
        while (t--) {
          p += ptn;
        }
        ptn = move(p);
      }
    }
    return ptn;
  }
};

int main() {
  //   string s = "2[abc]3[cd]ef";
  //   string s = "3[a2[c]]";
  string s = "10leetcode";
  Solution solution;
  cout << solution.decodeString(s) << endl;
  return 0;
}