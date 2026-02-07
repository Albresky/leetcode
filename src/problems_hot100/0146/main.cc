#include <cstring>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct LruNode {
  int key;
  int val;
  LruNode *prev;
  LruNode *next;
  LruNode() : key(0), val(0), prev(nullptr), next(nullptr) {}
  LruNode(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
  LruNode(int k, int v, LruNode *prev, LruNode *next)
      : key(k), val(v), prev(prev), next(next) {}
};

class LRUCache {
private:
  LruNode *data = nullptr;
  unordered_map<int, LruNode *> map;
  int capacity = 0;
  int occupied = 0;

  void moveFront(LruNode *node) {
    auto phead = data;
    if (phead == node)
      return;
    node->prev->next = node->next;
    node->next->prev = node->prev;
    node->next = phead;
    node->prev = phead->prev;
    phead->prev->next = node;
    phead->prev = node;
    data = node;
  }

public:
  LRUCache(int capacity) : capacity(capacity), occupied(0) {}

  int get(int key) {
    if (map.contains(key)) {
      auto node = map[key];
      moveFront(node);
      return map[key]->val;
    }

    else
      return -1;
  }

  void put(int key, int value) {
    if (map.contains(key)) {
      auto node = map[key];
      node->val = value;
      moveFront(node);
    } else {
      auto newNode = new LruNode(key, value);
      if (!data) {
        newNode->next = newNode->prev = newNode;
        data = newNode;
      } else {
        newNode->next = data;
        newNode->prev = data->prev;
        data->prev->next = newNode;
        data->prev = newNode;
      }
      data = newNode;
      map[key] = newNode; // insert
      ++occupied;
      if (occupied > capacity) {
        // deprecate LRU
        auto last = data->prev;
        map.erase(map.find(last->key));
        last->prev->next = data;
        data->prev = last->prev;
        delete last;
        --occupied;
      }
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
  LRUCache *lRUCache = nullptr;

  auto executor = [&lRUCache](vector<string> &action,
                              vector<vector<int>> &value) {
    if (action.size() != value.size()) {
      cout << "input invalid" << endl;
      exit(-1);
    }
    cout << "[";
    for (int i = 0; i < action.size(); ++i) {
      auto act = action[i];
      auto val = value[i];
      if (act == "LRUCache") {
        lRUCache = new LRUCache(val[0]);
        cout << "null";
      } else if (act == "put") {
        lRUCache->put(val[0], val[1]);
        cout << ", null";
      } else if (act == "get") {
        cout << ", " << lRUCache->get(val[0]);
      }
    }
    cout << "]\n";
  };

  /* tb1 */
  //   vector<string> actions = {"LRUCache", "put", "put", "get", "put",
  //                             "get",      "put", "get", "get", "get"};
  //   vector<vector<int>> values = {{2}, {1, 1}, {2, 2}, {1}, {3, 3},
  //                                 {2}, {4, 4}, {1},    {3}, {4}};

  /* tb2 */
  vector<string> actions = {
      "LRUCache", "put", "put", "put", "put", "put", "get", "put", "get",
      "get",      "put", "get", "put", "put", "put", "get", "put", "get",
      "get",      "get", "get", "put", "put", "get", "get", "get", "put",
      "put",      "get", "put", "get", "put", "get", "get", "get", "put",
      "put",      "put", "get", "put", "get", "get", "put", "put", "get",
      "put",      "put", "put", "put", "get", "put", "put", "get", "put",
      "put",      "get", "put", "put", "put", "put", "put", "get", "put",
      "put",      "get", "put", "get", "get", "get", "put", "get", "get",
      "put",      "put", "put", "put", "get", "put", "put", "put", "put",
      "get",      "get", "get", "put", "put", "put", "get", "put", "put",
      "put",      "get", "put", "put", "put", "get", "get", "get", "put",
      "put",      "put", "put", "get", "put", "put", "put", "put", "put",
      "put",      "put"};
  vector<vector<int>> values = {
      {10},     {10, 13}, {3, 17},  {6, 11},  {10, 5}, {9, 10},  {13},
      {2, 19},  {2},      {3},      {5, 25},  {8},     {9, 22},  {5, 5},
      {1, 30},  {11},     {9, 12},  {7},      {5},     {8},      {9},
      {4, 30},  {9, 3},   {9},      {10},     {10},    {6, 14},  {3, 1},
      {3},      {10, 11}, {8},      {2, 14},  {1},     {5},      {4},
      {11, 4},  {12, 24}, {5, 18},  {13},     {7, 23}, {8},      {12},
      {3, 27},  {2, 12},  {5},      {2, 9},   {13, 4}, {8, 18},  {1, 7},
      {6},      {9, 29},  {8, 21},  {5},      {6, 30}, {1, 12},  {10},
      {4, 15},  {7, 22},  {11, 26}, {8, 17},  {9, 29}, {5},      {3, 4},
      {11, 30}, {12},     {4, 29},  {3},      {9},     {6},      {3, 4},
      {1},      {10},     {3, 29},  {10, 28}, {1, 20}, {11, 13}, {3},
      {3, 12},  {3, 8},   {10, 9},  {3, 26},  {8},     {7},      {5},
      {13, 17}, {2, 27},  {11, 15}, {12},     {9, 19}, {2, 15},  {3, 16},
      {1},      {12, 17}, {9, 1},   {6, 19},  {4},     {5},      {5},
      {8, 1},   {11, 7},  {5, 2},   {9, 28},  {1},     {2, 2},   {7, 4},
      {4, 22},  {7, 24},  {9, 26},  {13, 28}, {11, 26}};
  executor(actions, values);

  return 0;
}