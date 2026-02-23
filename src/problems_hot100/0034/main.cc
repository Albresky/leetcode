#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    int start = binarySearch(nums, target);
    if (start == nums.size() || target != nums[start]) {
      return {-1, -1};
    }
    int end = binarySearch(nums, target + 1) - 1;
    return {start, end};
  }

  int binarySearch(vector<int> &nums, int target) {
    int l = 0, r = (int)nums.size() - 1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (target <= nums[mid])
        r = mid - 1;
      else
        l = mid + 1;
    }
    return l;
  }
};

int main() {
  vector<int> nums = {5, 7, 7, 8, 8, 10};
  int target = 8;
  Solution s;
  auto rtn = s.searchRange(nums, target);
  printf("[%d, %d]\n", rtn[0], rtn[1]);
  return 0;
}