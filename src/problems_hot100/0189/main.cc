#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void rotate(vector<int> &nums, int k) {
    int len = nums.size();
    vector<int> rotated(len);

    for (int i = 0; i < len; ++i)
      rotated[(i + k) % len] = nums[i];
    nums.assign(rotated.begin(), rotated.end());
  }
  void rotate2(vector<int> &nums, int k) {
    int len = nums.size();

    auto reverse = [&](int left, int right) {
      for (; left < right; ++left, --right)
        swap(nums[left], nums[right]);
    };

    k %= len;
    reverse(0, len - 1);
    reverse(0, k - 1);
    reverse(k, len - 1);
  }
};

int main() {
  vector<int> nums = {1, 2};
  int k = 2;
  //   vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
  //   int k = 3;
  Solution s;
  s.rotate2(nums, k);
  for (auto num : nums)
    cout << num << ", ";
  return 0;
}