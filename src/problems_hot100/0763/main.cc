#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> partitionLabels(string s) {
    vector<int> lens;
    vector<int> last(26);
    for (int i = 0; i < s.length(); ++i) {
      last[s[i] - 'a'] = i;
    }

    int left = 0, right = 0;
    for (int i = 0; i < s.length(); ++i) {
      right = max(right, last[s[i] - 'a']);
      if (i == right) {
        lens.push_back(i - left + 1);
        left = i + 1;
      }
    }
    return lens;
  }
};

int main() {
  string s = "ababcbacadefegdehijhklij";
  Solution solution;
  auto ret = solution.partitionLabels(s);
  for (auto &num : ret) cout << num << ", ";
  return 0;
}