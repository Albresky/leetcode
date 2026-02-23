#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int findMin(vector<int> &nums) {
    int l = 0, r = nums.size() - 1;
    int ans = 5001;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (nums[l] <= nums[mid]) {
        ans = min(nums[l], ans);
        l = mid + 1;
      } else {
        ans = min(nums[mid], ans);
        r = mid - 1;
      }
    }
    return ans;
  }
};

int main() {
  vector<int> nums = {3, 4, 5, 1, 2};
  Solution s;
  cout << s.findMin(nums) << endl;
  return 0;
}
