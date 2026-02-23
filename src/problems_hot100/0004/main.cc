#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int len = nums1.size() + nums2.size();
    if (len % 2 == 0) {
      return (findKthSmall(nums1, nums2, len / 2) +
              findKthSmall(nums1, nums2, len / 2 + 1)) /
             2.0;
    } else {
      return findKthSmall(nums1, nums2, len / 2 + 1) * 1.0;
    }
  }

  int findKthSmall(const vector<int> &nums1, const vector<int> &nums2, int k) {
    int m = nums1.size();
    int n = nums2.size();
    int mid1 = 0;
    int mid2 = 0;
    for (;;) {
      if (mid1 == m)
        return nums2[mid2 + k - 1];
      if (mid2 == n)
        return nums1[mid1 + k - 1];
      if (k == 1)
        return min(nums1[mid1], nums2[mid2]);

      int newMid1 = min(mid1 + k / 2 - 1, m - 1);
      int newMid2 = min(mid2 + k / 2 - 1, n - 1);

      if (nums1[newMid1] < nums2[newMid2]) {
        k -= newMid1 - mid1 + 1;
        mid1 = newMid1 + 1;
      } else {
        k -= newMid2 - mid2 + 1;
        mid2 = newMid2 + 1;
      }
    }
  }
};

int main() {
  vector<int> nums1 = {1, 3, 5, 7, 9};
  vector<int> nums2 = {2, 4, 6, 8, 10};
  Solution s;
  cout << s.findMedianSortedArrays(nums1, nums2) << endl;
  return 0;
}