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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    if (l1->val == 0 && !l1->next)
      return l2;
    else if (l2->val == 0 && !l2->next)
      return l1;

    ListNode *rtn = new ListNode();
    ListNode *p1 = l1, *p2 = l2, *pr = rtn;
    int commit = 0;
    while (p1 && p2) {
      int sum = p1->val + p2->val + commit;
      commit = sum / 10;
      pr->next = new ListNode(sum % 10);
      pr = pr->next;
      p1 = p1->next;
      p2 = p2->next;
    }
    ListNode *prest = p1 ? p1 : p2;
    while (prest) {
      int sum = prest->val + commit;
      commit = sum / 10;
      pr->next = new ListNode(sum % 10);
      pr = pr->next;
      prest = prest->next;
    }
    if (commit) {
      pr->next = new ListNode(commit);
    }
    return rtn->next;
  }
};

int main() {
  // vector<int> a = {2, 4, 3}, b = {5, 6, 4};
  // vector<int> a = {0}, b = {0};
  // vector<int> a = {1,2,3,4}, b = {5,6,7,8};
  vector<int> a = {9, 9, 9, 9, 9, 9, 9}, b = {9, 9, 9, 9};
  ListNode *l1 = vec1d2list<ListNode>(a);
  ListNode *l2 = vec1d2list<ListNode>(b);
  Solution s;
  auto rtn = s.addTwoNumbers(l1, l2);
  printList(rtn);
  return 0;
}