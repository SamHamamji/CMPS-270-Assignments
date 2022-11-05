#include <iostream>
#include <vector>

using namespace std;

template <class T> class Stack {
private:
  vector<T> list;

public:
  /**
    @returns a bool representing whether the stack is empty or not
  */
  bool empty() const { return list.size() == 0; }

  /**
    Pushes `item` to the top of the stack
    @input:
      `T &item` a reference to an element of type `T`
  */
  void push(const T &item) { list.push_back(item); }

  /**
    @returns a pointer to the top of the Stack
    @requires:
      The Stack is not empty, otherwise, exits the program
    @tested:
      Empty Stacks
      One element
      Multiple elements
  */
  T *top() {
    if (!this->empty()) {
      return &list.back();
    } else {
      cout << "ERROR: Cannot read top, stack is empty" << endl;
      exit(1);
    }
  }

  /**
    Removes the top of the Stack
    @requires:
      Stack is not empty, otherwise, exits the program
    @tested:
      Empty Stacks
      One element
      Multiple elements
  */
  void pop() {
    if (!this->empty()) {
      list.pop_back();
    } else {
      cout << "ERROR: Cannot pop, stack is empty" << endl;
      exit(1);
    }
  }

  /**
    Prints the Stack to stdout, the top being the rightmost element
    @effects:
      Empties the Stack
    @examples:
      { }
      { 1, -2, 3, 7 }
  */
  void print() {
    cout << "{ ";
    if (!this->empty()) {
      while (true) {
        T temp_top = *this->top();
        cout << temp_top;
        this->pop();
        if (!this->empty()) {
          cout << ", ";
        } else {
          break;
        }
      }
      cout << " }" << endl;
    }
  }

  /**
    Adds the element of `Stack b` on top of those in `Stack a`, without
    reversing their order
    @tested:
      `a` or `b` are empty (inclusive)
      `a` and  `b` have different sizes
  */
  template <T> friend Stack<T> operator+(Stack<T> a, Stack<T> b);
};

template <class T> Stack<T> operator+(Stack<T> a, Stack<T> b) {
  Stack<int> temp;
  Stack<int> sum;
  while (!b.empty()) {
    temp.push(*b.top());
    b.pop();
  }
  while (!a.empty()) {
    temp.push(*a.top());
    a.pop();
  }
  while (!temp.empty()) {
    sum.push(*temp.top());
    temp.pop();
  }
  return sum;
}

int main() {
  Stack<int> a, b, c;
  for (int i : {1, 2, 3}) {
    a.push(i);
  }
  for (int i : {4, 5}) {
    b.push(i);
  }
  for (int i : {2, -7, -3, 5, 0}) {
    c.push(i);
  }

  cout << "Example of a stack:" << endl;
  cout << "c = ";
  c.print();
  cout << "     top        bottom" << endl << endl;

  const int len = 4;
  string expressions[len] = {"a + b", "b + a", "a + a", "b + b"};
  Stack<int> sums[len] = {a + b, b + a, a + a, b + b};

  cout << "Adding a = {1, 2, 3} and b = {4, 5}:" << endl;
  for (int i = 0; i < len; i++) {
    cout << expressions[i] << " = ";
    sums[i].print();
  }

  return 0;
}