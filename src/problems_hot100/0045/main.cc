#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int jump(vector<int> &nums) {
    int curRange = 0, maxRange = 0, ans = 0;
    for (int i = 0; i < nums.size() - 1; ++i) {
      maxRange = max(maxRange, i + nums[i]);
      if (i == curRange) {
        curRange = maxRange;
        ++ans;
      }
    }
    return ans;
  }
};

int main() {
  vector<int> nums = {2, 3, 1, 1, 4};
  Solution s;
  cout << s.jump(nums) << endl;
  return 0;
}
