/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: string_to_integer.cpp,v 0.0 2015-07-06 星期一 22:27:21  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   string_to_integer.cpp
 * @author zhoujin
 * @date   2015-07-06 星期一 22:27:21
 * @mail   zhoujin1224@gmail.com
 * @brief  Implement atoi to convert a string to an integer.
 *
 * Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
 *
 * Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
 *
 * Update (2015-02-10):
 * The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
 *
 **/

#include <iostream>
#include <string>
#include <limits.h>

using namespace std;

class Solution {
  public:
    int myAtoi(string str) {
        if (str.empty()) {
            return 0;
        }
        int ret = 0;
        bool last_is_space = true;
        int is_pos = 1;
        for (int i = 0; i < str.length(); ++i) {
            if (last_is_space && str[i] == ' ') {
                continue;
            }
            if (last_is_space &&  (str[i] == '-' or str[i] == '+')) {
                if (str[i] == '-') {
                    is_pos = -1;
                }
                last_is_space = false;
                continue;
            } 
            if (str[i] < '0' or str[i] > '9') {
                //return 0;
                // 题意不是遇到错误字符返回0
                return ret * is_pos;
            } else {
                last_is_space = false;
                int remain = str[i] - '0';
                if (ret * is_pos > (INT_MAX - remain)/ 10) {
                    return INT_MAX;
                } else if (ret * is_pos < (INT_MIN + remain) / 10) {
                    return INT_MIN; 
                }
                ret = ret * 10 + remain;
            }
        }

        return ret * is_pos;
    }
};

int main() {
    string a = "123  456";
    Solution sol = Solution();
    cout << sol.myAtoi(a) << endl;

    return 0;
}
