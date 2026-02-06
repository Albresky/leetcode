#include "../../Helper/TreeNode.h"

using namespace std;

class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = nullptr;
    random = nullptr;
  }
};

void printListAddr(Node *head) {
  auto phead = head;
  while (phead) {
    cout << phead->val << "\t" << phead << ", next: " << phead->next
         << ", random: ";
    if (phead->random)
      cout << phead->random;
    else
      cout << "null";
    cout << "\n";
    phead = phead->next;
  }
}

class Solution {
public:
  Node *copyRandomList(Node *head) {
    // We dont use hashTable here, instead, this method refers to 0x3F.

    // create zip list
    auto phead = head;
    auto cpHead = new Node(0);
    auto pcphead = cpHead;
    while (phead) {
      auto node = new Node(phead->val);
      node->next = phead->next;
      phead->next = node;
      phead = phead->next->next;
    }

    // copy random
    phead = head;
    while (phead) {
      auto cpnode = phead->next;
      cpnode->random = phead->random ? phead->random->next : nullptr;
      phead = phead->next->next;
    }

    phead = head;
    // recover list and create cpnode
    while (phead) {
      auto cpnode = phead->next;
      phead->next = phead->next->next;
      phead = phead->next;
      pcphead->next = cpnode;
      pcphead = cpnode;
    }
    auto rtn = cpHead->next;
    delete cpHead;
    return rtn;
  }
};

int main() {
  auto n1 = new Node(7);
  auto n2 = new Node(13);
  auto n3 = new Node(11);
  auto n4 = new Node(10);
  auto n5 = new Node(1);
  n2->random = n1;
  n3->random = n5;
  n4->random = n3;
  n5->random = n1;
  auto head = n1;
  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;

  auto printRdList = [](Node *head) {
    auto phead = head;
    cout << "[";
    while (phead) {
      cout << "[" << phead->val << ",";
      if (phead->random)
        cout << phead->random->val;
      else
        cout << "null";
      cout << "],";
      phead = phead->next;
    }
    cout << "]" << endl;
  };
  cout << "\n\noriginal: \n";
  printRdList(head);
  printListAddr(head);

  Solution s;
  auto rtn = s.copyRandomList(head);
  cout << "\n\noriginal: \n";
  printRdList(head);
  printListAddr(head);
  cout << "\n\ncopied: \n";
  printRdList(rtn);
  printListAddr(rtn);
}