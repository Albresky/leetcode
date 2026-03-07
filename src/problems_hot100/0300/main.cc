#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    vector<int> dp(nums.size(), 1);
    int MAX = 1;
    for (int i = 1; i < nums.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        if (nums[i] > nums[j]) dp[i] = max(dp[i], 1 + dp[j]);
      }
      MAX = max(MAX, dp[i]);
    }
    return MAX;
  }
};

int main() {
  vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
  Solution s;
  cout << s.lengthOfLIS(nums) << endl;
  return 0;
}