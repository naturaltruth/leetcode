/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: min_stack.cpp,v 0.0 2015-07-28 星期二 21:28:29  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   min_stack.cpp
 * @author zhoujin
 * @date   2015-07-28 星期二 21:28:29
 * @mail   zhoujin1224@gmail.com
 * @brief  Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 *
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 *
 **/

#include <iostream>
#include <stack>

using namespace std;

class MinStack {
  public:
    void push(int x) {
        elem_stack.push(x);
        if (min_stack.size() > 0) { //attention here
            if (x < min_stack.top()) {
                min_stack.push(x);
            } else {
                min_stack.push(min_stack.top());
            }
        } else {
            min_stack.push(x);
        }
    }

    void pop() {
        if (elem_stack.size() > 0 && min_stack.size() > 0) {
            elem_stack.pop();
            min_stack.pop();
        }
    }

    int top() {
        return elem_stack.top();
    }

    int getMin() {
        return min_stack.top();
    }
  private:
    stack<int> elem_stack;
    stack<int> min_stack;
};
