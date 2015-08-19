/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: implement_stack_using_queues.cpp,v 0.0 2015-08-19 星期三 23:00:52  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   implement_stack_using_queues.cpp
 * @author zhoujin
 * @date   2015-08-19 星期三 23:00:52
 * @mail   zhoujin1224@gmail.com
 * @brief  Implement the following operations of a stack using queues.
 *
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * empty() -- Return whether the stack is empty.
 * Notes:
 * You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
 * Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
 * You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
 * Update (2015-06-11):
 * The class name of the Java function had been updated to MyStack instead of Stack.
 *
 **/

#include <iostream>
#include <queue>

using namespace std;

class Stack {
  public:
    // Push element x onto stack.
    void push(int x) {
        if (q1.empty()) {
            q1.push(x);
            int len = q2.size();
            for (int i = 0; i < len; ++i) {
                q1.push(q2.front());
                q2.pop();
            }
        } else {
            q2.push(x);
            int len = q1.size();
            for (int i = 0; i < len; ++i) {
                q2.push(q1.front());
                q1.pop();
            }
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        if (!q1.empty()) q1.pop();
        if (!q2.empty()) q2.pop();
    }

    // Get the top element.
    int top() {
        if (!q1.empty()) return q1.front();
        else return q2.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty() && q2.empty();
    }
  private:
    queue<int> q1, q2;
};


int main() {
    Stack s = Stack();

    s.push(2);
    s.push(3);

    cout << s.top() << endl;
    cout << s.empty() << endl;

    s.pop();

    cout << s.top() << endl;

    s.pop();
    cout << s.empty() << endl;

    return 0;
}
