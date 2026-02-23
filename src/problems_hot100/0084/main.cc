#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    int n = heights.size();
    int maxArea = 0;
    vector<int> left(n, -1);
    vector<int> right(n, n);
    stack<int> sleft, sright;

    for (int l = 0; l < n; ++l) {
      int h = heights[l];
      while (!sleft.empty() && h <= heights[sleft.top()]) {
        sleft.pop();
      }
      if (!sleft.empty()) left[l] = sleft.top();
      sleft.push(l);
    }

    for (int r = n - 1; r >= 0; --r) {
      int h = heights[r];
      while (!sright.empty() && h <= heights[sright.top()]) {
        sright.pop();
      }
      if (!sright.empty()) right[r] = sright.top();
      sright.push(r);
    }

    for (int k = 0; k < n; ++k) {
      maxArea = max(maxArea, heights[k] * ((right[k] - 1) - (left[k] + 1) + 1));
    }

    return maxArea;
  }
};

int main() {
  vector<int> heights = {2, 1, 5, 6, 2, 3};
  Solution s;
  cout << s.largestRectangleArea(heights) << endl;
  return 0;
}