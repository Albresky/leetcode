#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    if (intervals.empty())
      return {};
    sort(intervals.begin(), intervals.end(),
         [](const vector<int> &a, const vector<int> &b) -> bool {
           return a[0] < b[0];
         });

    vector<vector<int>> rtn;
    for (auto &vec : intervals) {
      if (rtn.empty())
        rtn.emplace_back(vec);
      else if (vec[0] <= rtn.back()[1])
        rtn.back()[1] = max(rtn.back()[1], vec[1]);
      else
        rtn.emplace_back(vec);
    }
    return rtn;
  }
};

int main() {
  vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  Solution s;
  auto rtn = s.merge(intervals);
  for (auto &vec : rtn)
    cout << '[' << vec[0] << ',' << vec[1] << ']';
}