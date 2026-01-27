#include <cstdint>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    int left = 0, right = 0;
    int len = nums.size();
    vector<int> rtn;
    priority_queue<pair<int, int>> pq;

    for (; right < left + k; ++right) {
      pq.emplace(nums[right], right);
    }
    rtn.emplace_back(pq.top().first);

    for (; right < len; ++right) {
      ++left;
      pq.emplace(nums[right], right);
      while (pq.top().second < left)
        pq.pop();
      rtn.emplace_back(pq.top().first);
    }
    return rtn;
  }
};

int main() {
  vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
  int k = 3;
  Solution s;
  auto rtn = s.maxSlidingWindow(nums, k);
  for (auto num : rtn)
    cout << num << ' ';
  return 0;
}