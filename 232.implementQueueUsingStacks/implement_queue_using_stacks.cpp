/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: implement_queue_using_stacks.cpp,v 0.0 2015-08-21 星期五 13:14:55  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   implement_queue_using_stacks.cpp
 * @author zhoujin
 * @date   2015-08-21 星期五 13:14:55
 * @mail   zhoujin1224@gmail.com
 * @brief
 * Implement the following operations of a queue using stacks.
 *
 * push(x) -- Push element x to the back of queue.
 * pop() -- Removes the element from in front of queue.
 * peek() -- Get the front element.
 * empty() -- Return whether the queue is empty.
 * Notes:
 * You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
 * Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
 * You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).
 *
 **/

#include <iostream>
#include <stack>

using namespace std;

class Queue {
  public:
    // Push element x to the back of queue.
    void push(int x) {
        if (s1.empty()) {
            while (!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
            s2.push(x);
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        } else {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(x);
            while (!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (!s1.empty()) s1.pop();
        if (!s2.empty()) s2.pop();
    }

    // Get the front element.
    int peek(void) {
        if (!s1.empty()) return s1.top();
        else return s2.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s1.empty() && s2.empty();
    }
  private:
    stack<int> s1, s2;
};


int main() {
    Queue q = Queue();
    q.push(1);
    q.push(2);
    q.push(3);

    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    cout << q.empty() << endl;
    q.pop();
    cout << q.empty() << endl;

    return 0;
}
