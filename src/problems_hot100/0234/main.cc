#include "../../Helper/TreeNode.h"

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  bool isPalindrome(ListNode *head) {

    // find mid node
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode *left = head;
    ListNode *right = (fast && fast != slow) ? slow->next : slow;

    // reverse last half
    ListNode *phead = right;
    ListNode *ptail = right;
    ListNode *next = right->next;
    while (next) {
      ListNode *temp = next->next;
      next->next = phead;
      phead = next;
      next = temp;
    }
    ptail->next = nullptr;
    right = phead;

    // check
    while (right) {
      if (left->val != right->val)
        return false;
      left = left->next;
      right = right->next;
    }
    return true;
  }
};

int main() {
  vector<int> list = {1};
  auto listnode = vec1d2list<ListNode>(list);
  Solution s;
  auto rtn = s.isPalindrome(listnode);
  cout << rtn << endl;
  return 0;
}