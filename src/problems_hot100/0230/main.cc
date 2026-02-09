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
  void dfs(TreeNode *root, int &k) {
    if (!root || k == 0) {
      return;
    }
    dfs(root->left, k);
    if (--k == 0)
      ans = root->val;
    dfs(root->right, k);
  }
  int ans;

public:
  int kthSmallest(TreeNode *root, int k) {
    dfs(root, k);
    return ans;
  }
};

int main() {
  vector<string> vec = {"3", "1", "4", "null", "2"};
  int k = 2;
  auto tree = vec2tree<TreeNode>(vec);
  Solution s;
  auto rtn = s.kthSmallest(tree, k);
  cout << rtn << endl;
  return 0;
}