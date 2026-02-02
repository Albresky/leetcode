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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    int len = 1;
    auto slow = head;
    auto fast = head;
    auto prev = slow;
    while (fast && fast->next) {
      ++len;
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    if (!fast)
      len = 2 * (len - 1);
    else
      len = 2 * len - 1;

    if (n <= (len + 1) / 2) {
      // move right
      for (int i = 0; i < (len + 1) / 2 - n; ++i) {
        prev = slow;
        slow = slow->next;
      }
    } else {
      prev = slow = head;
      for (int j = 0; j < len - n; ++j) {
        prev = slow;
        slow = slow->next;
      }
    }
    // remove n-th node
    if (slow == head)
      return head->next;
    else {
      prev->next = slow->next;
      return head;
    }
  }

  ListNode *removeNthFromEndOptimized(ListNode *head, int n) {
    auto slow = head;
    auto fast = head;
    auto prev = slow;
    for (int i = 0; i < n - 1; ++i) {
      fast = fast->next;
    }

    while (fast->next) {
      fast = fast->next;
      prev = slow;
      slow = slow->next;
    }

    if (slow == head)
      return head->next;
    else {
      prev->next = slow->next;
      return head;
    }
  }
};

int main() {
  vector<int> head = {1, 2, 3, 4, 5};
  //   vector<int> head = {1};
  //   vector<int> head = {1,2};
  int n = 2;
  auto list = vec1d2list<ListNode>(head);
  Solution s;
  auto rtn = s.removeNthFromEnd(list, n);
  printList(rtn);
  return 0;
}