#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
      int mid = (l + r) / 2;
      if (nums[mid] == target)
        return mid;
      if (nums[mid] < target) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    if (target <= nums[l])
      return l;
    else
      return l + 1;
  }
};

int main() {
  vector<int> nums = {1, 3, 5, 6};
  int target = 0;
  Solution s;
  cout << s.searchInsert(nums, target);
  return 0;
}