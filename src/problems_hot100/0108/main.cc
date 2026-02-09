#include "../../Helper/TreeNode.h"

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
private:
  TreeNode *dfs(vector<int> &nums, int left, int right) {
    if (left > right)
      return nullptr;

    int mid = (left + right) / 2;
    auto node = new TreeNode(nums[mid]);
    node->left = dfs(nums, left, mid - 1);
    node->right = dfs(nums, mid + 1, right);
    return node;
  }

public:
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    return dfs(nums, 0, nums.size() - 1);
  }
};

int main() {
  vector<int> vec = {-10, -3, 0, 5, 9};
  Solution s;
  auto rtn = s.sortedArrayToBST(vec);
  printTreeH(rtn);
  return 0;
}