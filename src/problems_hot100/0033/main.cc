#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    int mid = (left + right) / 2;
    if (nums[0] == target)
      return 0;
    while (left < right) {
      if (nums[mid] == target)
        return mid;

      if (nums[left] <= nums[mid]) {
        if (nums[left] <= target && target <= nums[mid])
          right = mid;
        else
          left = mid + 1;
      } else {
        if (nums[mid + 1] <= target && target <= nums[right])
          left = mid + 1;
        else
          right = mid;
      }
      mid = (left + right) / 2;
    }
    return nums[mid] == target ? mid : -1;
  }
};

int main() {
  vector<int> vec = {5, 1, 3};
//   vector<int> vec = {4, 5, 6, 7, 0, 1, 2};
//   vector<int> vec = {1};
//   vector<int> vec = {3, 4, 5, 6, 1, 2};
  int target = 5;
  Solution s;
  std::cout << s.search(vec, target) << std::endl;
  return 0;
}
