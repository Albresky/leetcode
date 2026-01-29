#include "../../Helper/TreeNode.h"
#include <iostream>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *pa = headA, *pb = headB;
    while (pa != pb) {
      if (pa)
        pa = pa->next;
      else
        pa = headB;
      if (pb)
        pb = pb->next;
      else
        pb = headA;
    }
    return pa;
  }
};
