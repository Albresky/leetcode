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
public:
  TreeNode *invertTree(TreeNode *root) {
    if (!root)
      return root;

    root->left = invertTree(root->left);
    root->right = invertTree(root->right);
    swap(root->left, root->right);
    return root;
  }
};

int main() {
  vector<string> vec = {"4", "2", "7", "1", "3", "6", "9"};
  //   vector<string> vec = {};
  auto tree = vec2tree<TreeNode>(vec);
  Solution s;
  auto rtn = s.invertTree(tree);
  printTreeH<TreeNode, int>(rtn);
  return 0;
}