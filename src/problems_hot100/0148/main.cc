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
  ListNode *findMid(ListNode *head) {
    auto slow = head;
    auto fast = head;
    auto prev = slow;
    while (fast && fast->next) {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    prev->next = nullptr;
    return slow; // 2nd list
  }

  ListNode *mergeSortedList(ListNode *l1, ListNode *l2) {
    auto head = new ListNode();
    auto phead = head;
    auto p1 = l1, p2 = l2;

    while (p1 && p2) {
      if (p1->val < p2->val) {
        phead->next = p1;
        p1 = p1->next;
      } else {
        phead->next = p2;
        p2 = p2->next;
      }
      phead = phead->next;
    }
    if (p1) {
      phead->next = p1;
    } else {
      phead->next = p2;
    }
    auto rtn = head->next;
    delete head;
    return rtn;
  }

  ListNode *sortList(ListNode *head) {
    if (!head || !head->next)
      return head;

    auto mid = findMid(head);
    auto l1 = sortList(head);
    auto l2 = sortList(mid);
    return mergeSortedList(l1, l2);
  }
};

int main() {
  vector<int> vec = {4, 2, 1, 3};
  auto list = vec1d2list<ListNode>(vec);

  Solution s;
  auto rtn = s.sortList(list);
  printList(rtn);
  return 0;
}