#include <iostream>
#include <stack>

class Queue {
 public:
  Queue();
  ~Queue();

  bool empty() { return s1_.empty() && s2_.empty(); }
  void appendTail(int val) { s1_.push(); }
  int deleteHead() {
    if (empty()) throw new exception("queue is empty");
    if (s2_.empty()) {
      while (!s1_.empty()) {
        s2_.push(s1_.top());
        s1_.pop();
      }
    }
    int tmp = s2_.top();
    s2_.pop();
    return tmp;
  }

 private:
  std::stack<int> s1_;
  std::stack<int> s2_;
}