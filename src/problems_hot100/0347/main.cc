#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> map;
    int maxf = 0;
    for (auto num : nums) {
      map[num]++;
      maxf = max(maxf, map[num]);
    }
    // using bucket-sort
    return doBucketSort(map, k, maxf);

    // using heap
    // return doHeapSort(map, k);
  }

private:
  vector<int> doBucketSort(unordered_map<int, int> &map, int k, int maxf) {
    vector<vector<int>> bucket(maxf + 1);

    for (auto [num, f] : map) {
      bucket[f].push_back(num);
    }

    vector<int> ans;
    for (int f = maxf; f > 0 && ans.size() < (size_t)k; --f) {
      ans.insert(ans.end(), bucket[f].begin(), bucket[f].end());
    }
    return ans;
  }

  vector<int> doHeapSort(unordered_map<int, int> &map, int k) {
    auto cmp = [](const pair<int, int> &a, const pair<int, int> &b) {
      return a.second > b.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(
        cmp);
    for (auto [num, f] : map) {
      if (pq.size() == (size_t)k) {
        if (pq.top().second < f) {
          pq.pop();
          pq.emplace(num, f);
        }
      } else {
        pq.emplace(num, f);
      }
    }

    vector<int> ans;
    while (!pq.empty()) {
      ans.emplace_back(pq.top().first);
      pq.pop();
    }
    return ans;
  }
};

int main() {
  vector<int> nums = {1, 2, 1, 2, 1, 2, 3, 1, 3, 2};
  int k = 2;
  Solution s;
  auto ans = s.topKFrequent(nums, k);
  for (auto num : ans) cout << num << ", ";
  cout << endl;
  return 0;
}