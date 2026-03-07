#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int rob(vector<int> &nums) {
    const int n = static_cast<int>(nums.size());
    if (n == 0)
      return 0;
    if (n == 1)
      return nums[0];

    int prev2 = nums[0];
    int prev1 = max(nums[0], nums[1]);
    for (int i = 2; i < n; ++i) {
      const int cur = max(prev1, prev2 + nums[i]);
      prev2 = prev1;
      prev1 = cur;
    }
    return prev1;
  }
};

int main() {
  vector<int> nums = {0};
  //   vector<int> nums = {2, 7, 9, 3, 1};
  //   vector<int> nums = {1,2,3,1};
  Solution s;
  auto ans = s.rob(nums);
  cout << ans << endl;
  return 0;
}