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
  ListNode *middleNode(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }
};

int main() {
  vector<int> list = {1, 2, 3, 4, 5, 6, 7, 8};
  auto listnode = vec1d2list<ListNode>(list);
  Solution s;
  auto rtn = s.middleNode(listnode);
  printList(rtn);
  return 0;
}