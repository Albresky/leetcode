#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int numSquares(int n) {
    vector<int> f(n + 1);
    for (int i = 1; i <= n; ++i) {
      int MIN = INT32_MAX;
      for (int j = 1; j * j <= i; ++j) {
        MIN = min(MIN, f[i - j * j]);
      }
      f[i] = 1 + MIN;
    }
    return f[n];
  }
};

int main() {
  int n = 12;
  Solution s;
  cout << s.numSquares(n) << endl;
  return 0;
}