#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
private:
  bool dfs(vector<int> &nums, vector<vector<int>> &map, int i, int j) {
    if (i < 0) return j == 0;

    int &visit = map[i][j];
    if (visit != -1) return visit;

    if (nums[i] > j) return visit = dfs(nums, map, i - 1, j);

    return visit =
               dfs(nums, map, i - 1, j - nums[i]) || dfs(nums, map, i - 1, j);
  }

public:
  bool canPartition(vector<int> &nums) {
    int n = nums.size();
    int sum = reduce(nums.begin(), nums.end());
    if (sum % 2) return false;

    vector<vector<int>> map(n, vector<int>(sum / 2 + 1, -1));

    return dfs(nums, map, n - 1, sum / 2);
  }

  bool canPartitionDP(vector<int> &nums) {
    int n = nums.size();
    int sum = reduce(nums.begin(), nums.end());
    if (sum % 2) return false;

    sum /= 2;

    // f[i][j] = f[i-1][j-nums[i]] V f[i-1][j], i: 0, n; j: 0, sum/2
    // f[i+1][j] = f[i][j-nums[i]] V f[i][j]
    vector<vector<int>> f(n + 1, vector<int>(sum + 1, false));
    f[0][0] = true;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= sum; ++j) {
        f[i + 1][j] = nums[i] <= j && f[i][j - nums[i]] || f[i][j];
      }
    }
    return f[n][sum];
  }
};

int main() {
  vector<int> nums = {1, 5, 11, 5};
  Solution s;
  cout << s.canPartitionDP(nums) << endl;
  return 0;
}