#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    int n = temperatures.size();
    vector<int> ans(n);
    stack<int> st;

    for (int i = 0; i < n; ++i) {
      int t = temperatures[i];
      while (!st.empty() && t > temperatures[st.top()]) {
        int j = st.top();
        st.pop();
        ans[j] = i - j;
      }
      st.push(i);
    }

    return ans;
  }
};

int main() {
  vector<int> temp = {73, 74, 75, 71, 69, 72, 76, 73};
  Solution s;
  auto rtn = s.dailyTemperatures(temp);
  for (auto i : rtn) cout << i << ", ";
  cout << endl;
  return 0;
}