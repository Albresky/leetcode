#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int minEatingSpeed(vector<int> &piles, int h) {
    int maxspeed = 0;
    for (auto pile : piles)
      maxspeed = max(maxspeed, pile);
    int left = 1;
    int right = maxspeed;
    int minspeed = maxspeed;
    while (left < right) {
      int speed = (left + right) / 2;

      int t = getTime(piles, speed);
      if (t <= h)
        minspeed = right = speed;
      if (t > h) {
        left = speed + 1;
      }
    }
    return minspeed;
  }

  int getTime(vector<int> &piles, int speed) {
    int t = 0;
    for (auto pile : piles) {
      t += (pile + speed - 1) / speed;
    }
    return t;
  }
};

int main() {
  vector<int> piles = {3, 6, 7, 11};
  //   vector<int> piles = {30, 11, 23, 4, 20};
  int h = 8;
  Solution s;
  std::cout << s.minEatingSpeed(piles, h) << std::endl;
  return 0;
}