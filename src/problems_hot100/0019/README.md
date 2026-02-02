# [mid] #0019 删除链表的倒数第 N 个结点

给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

## 思路

都是用双指针，重点记录下方法二，思路巧妙。

**方法一**

快慢指针计算链表长度（时间复杂度$O(\frac{N}{2})$，然后再遍历一次删除倒数第 n 个节点（最坏时间复杂度$O(\frac{N}{2})$）。

**方法二**

双指针，先让快指针走 n-1 步（此时慢指针是快指针的倒数第 n 个节点），然后两个指针一起走，当快指针到达尾节点时，慢指针正好到达链表的倒数第 n 个节点，然后删除该节点。

```cpp
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
```
