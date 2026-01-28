#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int firstMissingPositive(vector<int> &nums) {
    int len = nums.size();
    for (int i = 0; i < len; ++i) {
      while (nums[i] > 0 && nums[i] <= len && nums[nums[i] - 1] != nums[i])
        swap(nums[nums[i] - 1], nums[i]);
    }

    for (int j = 0; j < len; ++j) {
      if (nums[j] != j + 1)
        return j + 1;
    }
    return len + 1;
  }
};

int main() {
  // vector<int> nums = {1,2,0};
  vector<int> nums = {3, 4, -1, 1};
  Solution s;
  cout << s.firstMissingPositive(nums);
  return 0;
}