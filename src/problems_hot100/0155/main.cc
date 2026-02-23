#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

class MinStack {
private:
  vector<pair<int, int>> data;

public:
  MinStack() { data.push_back(pair(0, INT32_MAX)); }

  void push(int val) {
    data.push_back(pair(val, min(data.back().second, val)));
  }

  void pop() {
    if (data.size() > 1)
      data.erase(data.end());
  }

  int top() { return data.back().first; }

  int getMin() { return data.back().second; }
};

int main() {
  auto minStack = new MinStack();
  minStack->push(-2);
  minStack->push(0);
  minStack->push(-3);
  cout << "getMin(): " << minStack->getMin() << endl;
  minStack->pop();
  cout << "top(): " << minStack->top() << endl;
  cout << "getMin(): " << minStack->getMin() << endl;
  delete minStack;
  return 0;
}