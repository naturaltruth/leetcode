/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: valid_parentheses.cpp,v 0.0 2015-07-16 星期四 07:14:52  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   valid_parentheses.cpp
 * @author zhoujin
 * @date   2015-07-16 星期四 07:14:52
 * @mail   zhoujin1224@gmail.com
 * @brief  Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 *
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 *
 **/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
  public:
    bool isValid(string s) {
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                sta.push(s[i]);
            } else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
                if (sta.empty()) {
                    return false;
                }
                if (s[i] == ')') {
                    if (sta.top() == '(') {
                        sta.pop();
                    } else {
                        return false;
                    }
                } else if (s[i] == '}') {
                    if (sta.top() == '{') {
                        sta.pop();
                    } else {
                        return false;
                    }
                } else if (s[i] == ']') {
                    if (sta.top() == '[') {
                        sta.pop();
                    } else {
                        return false;
                    }
                }
            }
        }
        
        return sta.empty();
    }

  private:
    stack<char> sta;
};

int main () {
    Solution sol = Solution();
    string s = "[({})]";
    cout << sol.isValid(s) << endl;
    s = "([)])";
    cout << sol.isValid(s) << endl;

    return 0;
}
