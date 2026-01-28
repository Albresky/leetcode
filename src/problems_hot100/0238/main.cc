#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int len = nums.size();
    vector<int> prefix(len);
    vector<int> suffix(len);
    vector<int> rtn(len);

    prefix[0] = suffix[len - 1] = 1;
    for (int i = 1, end = len - 1; i < len; ++i) {
      prefix[i] = prefix[i - 1] * nums[i - 1];
      suffix[end - i] = suffix[end - i + 1] * nums[end - i + 1];
    }

    for (int j = 0; j < len; ++j)
      rtn[j] = prefix[j] * suffix[j];
    return rtn;
  }
};

int main() {
  vector<int> nums = {1, 2, 3, 4};
  Solution s;
  auto rtn = s.productExceptSelf(nums);
  for (auto &num : rtn)
    cout << num << " ";
  return 0;
}