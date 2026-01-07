#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    /* return fastSelect(nums, k); */
    return fastSelect(nums, 0, nums.size() - 1, k - 1);
  }
  int fastSelect(vector<int> &nums, int k) {
    // gt, eq, lt
    vector<int> gt, eq, lt;
    auto base = nums[rand() % nums.size()];

    // 3-way group
    for (auto num : nums) {
      if (num > base) {
        gt.push_back(num);
      } else if (num < base) {
        lt.push_back(num);
      } else {
        eq.push_back(num);
      }
    }

    if (k <= gt.size()) {
      return fastSelect(gt, k);
    } else if (k > nums.size() - lt.size()) {
      return fastSelect(lt, k - (nums.size() - lt.size()));
    } else {
      return base;
    }
  }

  int fastSelect(vector<int> &nums, int left, int right, int k) {
    if (left >= right)
      return nums[left];
    int base = nums[left + rand() % (right - left + 1)];
    int l = left;
    int r = right;
    int i = l;
    // 3-way inplace group
    while (i <= r) {
      if (nums[i] > base) {
        swap(nums[l], nums[i]);
        ++l;
        ++i;
      } else if (nums[i] < base) {
        swap(nums[r], nums[i]);
        --r;
      } else {
        ++i;
      }
    }

    if (k < l)
      return fastSelect(nums, left, l - 1, k);
    else if (k > r)
      return fastSelect(nums, r + 1, right, k);
    else
      return base;
  }
};

int main() {
  vector<int> vec = {3, 2, 3, 1, 2, 4, 5, 5, 6};
  Solution s;
  int k = 4;
  cout << s.findKthLargest(vec, k) << endl;
  return 0;
}