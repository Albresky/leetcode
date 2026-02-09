#include "../../Helper/TreeNode.h"
#include <unordered_map>
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
  int cnt = 0;
  unordered_map<long long, int> map;

  void dfs(TreeNode *root, int targetSum, long long sum) {
    if (!root)
      return;

    sum += root->val;
    if (map.contains(sum - targetSum)) {
      cnt += map[sum - targetSum];
    }
    ++map[sum];
    dfs(root->left, targetSum, sum);
    dfs(root->right, targetSum, sum);
    --map[sum];
  }

public:
  int pathSum(TreeNode *root, int targetSum) {
    map[0] = 1;
    dfs(root, targetSum, 0);
    return cnt;
  }
};

int main() {
  vector<string> vec = {"10", "5", "-3", "3",    "2", "null",
                        "11", "3", "-2", "null", "1"};
  auto tree = vec2tree<TreeNode>(vec);
  int targetSum = 8;
  Solution s;
  cout << s.pathSum(tree, targetSum) << endl;
  return 0;
}