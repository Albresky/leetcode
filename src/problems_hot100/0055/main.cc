#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool canJump(vector<int> &nums) {
    int maxpos = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (maxpos < i) return false;
      maxpos = max(maxpos, i + nums[i]);
    }
    return true;
  }
};

int main() {
  vector<int> nums = {3, 2, 1, 0, 4};
  Solution s;
  cout << s.canJump(nums) << endl;
  return 0;
}