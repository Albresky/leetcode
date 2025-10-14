#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        clen = candidates.size();
        auto combined = vector<int>();
        dfs(combined, candidates, target, 0);
        return res;
    }

   private:
    vector<vector<int>> res;
    int clen;

    void dfs(vector<int> &combined, vector<int> &candidates, int target, int idx) {
        if (!target) {
            res.emplace_back(combined);
            combined.pop_back();
            return;
        } else if (target < 0 || idx == clen) {
            if (combined.size()) combined.pop_back();
            return;
        }

        combined.emplace_back(candidates[idx]);
        dfs(combined, candidates, target - candidates[idx], idx);
        dfs(combined, candidates, target, idx + 1);
    }
};

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    Solution s;
    auto res = s.combinationSum(candidates, target);
    for (auto &v : res) {
        for (auto &n : v) cout << n << " ";
        cout << endl;
    }
    return 0;
}