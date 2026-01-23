#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> rtn;

    sort(nums.begin(), nums.end());

    int a, b, c; // a<b<c
    int N = nums.size();

    for (a = 0; a < N; ++a) {
      if (a > 0 && nums[a] == nums[a - 1])
        continue;
      int target = -nums[a];
      for (b = a + 1, c = N - 1; b < N; ++b) {
        if (b > a + 1 && nums[b] == nums[b - 1])
          continue;

        for (; b < c && nums[b] + nums[c] > target;) {
          --c;
        }
        if (b == c)
          break;

        if (target == nums[b] + nums[c])
          rtn.emplace_back(vector<int>{nums[a], nums[b], nums[c]});
      }
    }
    return rtn;
  }
};

int main() {
  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  Solution s;
  auto rtn = s.threeSum(nums);
  for (auto &vec : rtn) {
    for (auto &n : vec)
      printf("%d ", n);
    printf("\n");
  }
}