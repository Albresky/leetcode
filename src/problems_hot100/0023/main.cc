#include "../../Helper/TreeNode.h"
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  struct VarNode {
    ListNode *node;
    VarNode(ListNode *newNode) : node(newNode) {}
    bool operator<(const VarNode addNode) const {
      return addNode.node->val < node->val;
    }
  };

  priority_queue<VarNode> q;

public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    // return linearMerge(lists);
    // return divideMerge(lists, 0, lists.size() - 1);
    return queueMerge(lists);
  }

  ListNode *linearMerge(vector<ListNode *> &lists) {
    ListNode *iter = nullptr;
    for (auto list : lists) {
      iter = mergeTwoLists(iter, list);
    }
    return iter;
  }

  ListNode *divideMerge(vector<ListNode *> &lists, int left, int right) {
    if (left == right)
      return lists[left];
    else if (left > right)
      return nullptr;

    auto mid = (left + right) / 2;
    return mergeTwoLists(divideMerge(lists, left, mid),
                         divideMerge(lists, mid + 1, right));
  }

  ListNode *queueMerge(vector<ListNode *> lists) {
    for (auto list : lists) {
      if (list != nullptr)
        q.push(list);
    }

    ListNode head, *p = &head;
    while (!q.empty()) {
      auto top = q.top().node;
      q.pop();
      p->next = top;
      p = p->next;
      if (top->next != nullptr)
        q.push(top->next);
    }
    return head.next;
  }

  ListNode *mergeTwoLists(ListNode *a, ListNode *b) {
    if (!a && b)
      return b;
    else if (a && !b)
      return a;
    ListNode head, *tail = &head;
    ListNode *pa = a, *pb = b;
    while (pa && pb) {
      if (pa->val < pb->val) {
        tail->next = pa;
        pa = pa->next;
      } else {
        tail->next = pb;
        pb = pb->next;
      }
      tail = tail->next;
    }
    if (pa)
      tail->next = pa;
    else
      tail->next = pb;
    return head.next;
  }
};

int main() {
  vector<vector<int>> list = {{1, 4, 5}, {1, 3, 4}, {2, 6}};
  // vector<vector<int>> list = {{0,2,5}};
  auto veclist = vec2d2veclist<ListNode, int, int>(list);
  Solution s;
  auto rtn = s.mergeKLists(veclist);
  printList(rtn);
  return 0;
}