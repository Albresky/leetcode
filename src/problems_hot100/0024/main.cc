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
  ListNode *swapPairs(ListNode *head) {
    ListNode *nhead = new ListNode();
    nhead->next = head;
    auto prev = nhead;
    auto p = prev->next;
    while (p && p->next) {
      prev->next = p->next;
      p->next = p->next->next;
      prev->next->next = p;
      prev = prev->next->next;
      p = prev->next;
    }
    auto rtn = nhead->next;
    delete nhead;
    return rtn;
  }
};

int main() {
  vector<int> vec = {1, 2, 3, 4};
  //   vector<int> vec = {};
  auto nodelist = vec1d2list<ListNode>(vec);
  Solution s;
  auto rtn = s.swapPairs(nodelist);
  printList(rtn);
  return 0;
}