#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    int bnd = s.size() / 2;

    int maxl = 0;
    for (auto &num : s) {
      if (s.contains(num - 1)) {
        continue;
      }
      int x = num + 1;
      for (; s.contains(x);) {
        ++x;
      }

      maxl = max(maxl, x - 1 - num + 1);
      if (maxl >= bnd) {
        break;
      }
    }
    return maxl;
  }
};

int main(){
    // vector<int> nums = {100,4,200,1,3,2};
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    Solution s;
    int len = s.longestConsecutive(nums);
    cout << len << endl;
    return 0;
}