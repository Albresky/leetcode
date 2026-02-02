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
  ListNode *reverseKGroup(ListNode *head, int k) {
    auto reverse = [](ListNode *prev, ListNode *tail) -> ListNode * {
      auto phead = prev->next;
      auto pnode = phead->next;
      auto pprev = phead;
      while (pnode && phead != tail) {
        auto next = pnode->next;
        pprev->next = next;
        pnode->next = phead;
        prev->next = pnode;
        phead = pnode;
        pnode = next;
      }
      return /* new Tail */ pprev;
    };

    auto newHead = new ListNode();
    newHead->next = head;
    auto prev = newHead, next = newHead;
    while (next) {
      for (int i = 0; i < k; ++i) {
        next = next->next;
        if (!next)
          return newHead->next;
      }
      ListNode *newNext = reverse(prev, next);
      prev = newNext;
      next = newNext;
    }
    return newHead->next;
  }
};

int main() {
  vector<int> vec = {1,2};
  int k = 2;
  auto list = vec1d2list<ListNode>(vec);
  Solution s;
  auto rtn = s.reverseKGroup(list, k);
  printList(rtn);
  return 0;
}