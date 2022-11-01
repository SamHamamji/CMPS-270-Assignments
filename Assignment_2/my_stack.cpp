#include <cstdlib>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

template <class T> class Stack {
private:
  vector<T> list;

public:
  int a;
  bool empty() const { return list.size() == 0; }
  void push(const T &item) { list.push_back(item); }
  T &top() {
    if (!this->empty()) {
      return list.back();
    } else {
      cout << "ERROR: Cannot pop, stack is empty" << endl;
      exit(1);
    }
  }
  void pop() {
    if (!this->empty()) {
      list.pop_back();
    } else {
      cout << "ERROR: Cannot pop, stack is empty" << endl;
      exit(1);
    }
  }
};

int main() {
  Stack<int> s = {};
  for (int i = 0; i < 10; i++) {
    s.push(i);
  }
  for (int i = 0; i < 10; i++) {
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl;
  return 0;
}