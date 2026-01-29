#include "../../Helper/TreeNode.h"

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    auto slow = head;
    auto fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (!fast)
        return nullptr;
      if (fast == slow) {
        auto p = head;
        while (p != slow) {
          p = p->next;
          slow = slow->next;
        }
        return p;
      }
    }
    return nullptr;
  }
};

int main() {
  vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto list = vec1d2list<ListNode>(vec);
  int p = 2; // 3

  // build ring at k
  auto *tail = list;
  auto *point = list;
  while (tail->next) {
    tail = tail->next;
  }
  while (p--) {
    point = point->next;
  }
  tail->next = point;

  // Solve
  Solution s;
  auto rtn = s.detectCycle(list);
  if (rtn)
    cout << rtn->val;
  else
    cout << "null";
  return 0;
}