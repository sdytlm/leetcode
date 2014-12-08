/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

*/

class MinStack {
private: stack<int> s;      // 正常stack
         stack<int> mStack;  // 维护一个stack, 栈顶总是最小的数
public:
  void push(int x) {
      s.push(x);
      if(mStack.empty() || mStack.top()>=x) // 新元素比以前最小的那个小或者新元素是第一个
          mStack.push(x);
  }

  void pop() {
      if(mStack.top()==s.top())  // 要pop的是最小的元素
          mStack.pop();
      s.pop();
  }

  int top() {
      return s.top();
  }

  int getMin() {
      return mStack.top();
  }
};
