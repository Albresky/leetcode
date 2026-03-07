#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int maxProduct(vector<int> &nums) {
    int prevMax = nums[0], prevMin = nums[0];
    int MAX = prevMax;
    for (int i = 1; i < nums.size(); ++i) {
        int _max = prevMax;
      prevMax = max({nums[i]*prevMax, nums[i]*prevMin, nums[i]});
      prevMin = min({_max*nums[i], prevMin*nums[i], nums[i]});

      MAX = max(MAX, prevMax);
    }
    return MAX;
  }
};

int main() {
  vector<int> nums = {-1, 2, 3, 6, 0, 5, 4, 9, 10, -1};
  Solution s;
  cout << s.maxProduct(nums) << endl;
  return 0;
}