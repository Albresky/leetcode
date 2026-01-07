#pragma once

#include <iostream>
#include <optional>
#include <queue>
#include <string>
#include <vector>

template <class NodeType, typename T = std::string, typename TV = int>
NodeType *vec2tree(const std::vector<T> &vec) {
  if (vec.empty() || vec[0] == "null")
    return nullptr;

  NodeType *root = new NodeType(static_cast<TV>(std::stoi(vec[0])));
  std::queue<NodeType *> q;
  q.push(root);

  size_t idx = 1;
  while (idx < vec.size()) {
    NodeType *curr = q.front();
    q.pop();

    // left son
    if (idx < vec.size() && vec[idx] != "null") {
      TV val = static_cast<TV>(std::stoi(vec[idx]));
      curr->left = new NodeType(val);
      q.push(curr->left);
    }
    ++idx;

    // right son
    if (idx < vec.size() && vec[idx] != "null") {
      TV val = static_cast<TV>(std::stoi(vec[idx]));
      curr->right = new NodeType(val);
      q.push(curr->right);
    }
    ++idx;
  }
  return root;
}

template <class NodeType, typename T = std::string, typename TV = int>
NodeType *vec1d2list(const std::vector<T> &vec) {
  if (vec.empty())
    return nullptr;
  if constexpr (std::is_same<T, std::string>::value) {
    if (vec[0] == "null")
      return nullptr;
  }
  NodeType head;
  auto pnode = &head;
  for (auto val : vec) {
    auto node = new NodeType(val);
    pnode->next = node;
    pnode = pnode->next;
  }
  // non-header list
  return head.next;
}

template <class NodeType, typename T = std::string, typename TV = int>
std::vector<NodeType *> vec2d2veclist(const std::vector<std::vector<T>> &vec) {
  // input: [[1,4,5],[1,3,4],[2,6]]
  // output [ListNode*, ListNode*, ListNode*]
  std::vector<NodeType *> veclist;
  for (const auto &v : vec) {
    veclist.push_back(vec1d2list<NodeType, T, TV>(v));
  }
  return veclist;
}

template <class NodeType> void printList(NodeType *head) {
  auto *p = head;
  while (p) {
    std::cout << p->val << " -> ";
    p = p->next;
  }
  std::cout << "nullptr" << std::endl;
}
