#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> sum(n + 1);
    for (int i = 0; i < n; ++i) {
      sum[i + 1] = nums[i] + sum[i];
    }

    int rtn = 0;
    unordered_map<int, int> map;
    for (auto j : sum) {
      // ... sum[i] ... sum[j] ...
      // sum[j] - sum [i] = k  ==> sum[j] - sum[j-k] = k
      if (map.contains(j - k))
        rtn += map[j - k];
      map[j]++;
    }
    return rtn;
  }
};

int main() {
  vector<int> nums = {1, 1, 1};
  int k = 3;
  Solution s;
  auto rtn = s.subarraySum(nums, k);
  cout << rtn << endl;
  return 0;
}