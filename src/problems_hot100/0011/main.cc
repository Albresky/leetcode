#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    const int len = height.size();
    int l = 0, r = len - 1;
    int v = 0, h = 0;
    for (; l < r;) {
      int d = r - l;
      if (height[l] < height[r]) {
        h = height[l];
        ++l;
      } else {
        h = height[r];
        --r;
      }
      v = max(v, h * d);
    }
    return v;
  }
};

int main(){
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution s;
    auto a = s.maxArea(height);
    std::cout << a << endl;
    return 0;
}