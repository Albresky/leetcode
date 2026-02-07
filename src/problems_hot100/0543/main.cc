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
  int dfs(TreeNode *root, int &maxlen) {
    if (!root)
      return 0;

    int lenl = dfs(root->left, maxlen);
    int lenr = dfs(root->right, maxlen);
    maxlen = max(maxlen, lenl + lenr);
    return max(lenl, lenr) + 1;
  }

public:
  int diameterOfBinaryTree(TreeNode *root) {
    int d = 0;
    dfs(root, d);
    return d;
  }
};

int main() {
  vector<string> vec = {"1", "2", "3", "4", "5"};
  auto tree = vec2tree<TreeNode>(vec);
  Solution s;
  auto rtn = s.diameterOfBinaryTree(tree);
  cout << rtn << endl;
  return 0;
}