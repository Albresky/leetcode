#include <functional>
#include <iostream>
#include <queue>

using namespace std;

class MedianFinder {
private:
  priority_queue<int> left;
  priority_queue<int, vector<int>, greater<>> right;

public:
  MedianFinder() {}

  void addNum(int num) {
    int lenl = left.size();
    int lenr = right.size();

    if (lenr == lenl) {
      // lenr == lenl
      right.emplace(num);
      left.emplace(right.top());
      right.pop();
    } else if (lenl - lenr == 1) {
      // lenl = lenr + 1
      left.emplace(num);
      right.emplace(left.top());
      left.pop();
    }
  }

  double findMedian() {
    int lenl = left.size();
    int lenr = right.size();
    if (lenl == lenr) {
      return (left.top() + right.top()) / 2.0;
    } else {
      return left.top() * 1.0;
    }
  }
};

int main() {
  auto medianFinder = new MedianFinder();
  medianFinder->addNum(1);                    // arr = [1]
  medianFinder->addNum(2);                    // arr = [1, 2]
  cout << medianFinder->findMedian() << endl; // 1.5
  medianFinder->addNum(3);                    // arr[1, 2, 3]
  cout << medianFinder->findMedian() << endl; // return 2.0
  delete medianFinder;
  return 0;
}