/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: palindrome_number.cpp,v 0.0 2015-07-14 星期二 00:02:40  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   palindrome_number.cpp
 * @author zhoujin
 * @date   2015-07-14 星期二 00:02:40
 * @mail   zhoujin1224@gmail.com
 * @brief  Determine whether an integer is a palindrome. Do this without extra space.
 *
 **/

#include <iostream>
#include <math.h>

using namespace std;

class Solution {
  public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        if (x < 10) {
            return true;
        }
        int len = 0;
        int x1 = x;
        while (x1 != 0) {
            x1 = x1 / 10;
            ++len;
        }
        for (int i = 0; i < len / 2; ++i) {
            if (int(x / pow(10, i)) % 10 != int(x / pow(10, len - 1 -i)) % 10) {
                return false;
            }
        }
        return true;        
    }
};

int main () {
    Solution sol = Solution();
    cout << sol.isPalindrome(12221) << endl;
    cout << sol.isPalindrome(1121) << endl;
    cout << sol.isPalindrome(-1) << endl;
    cout << sol.isPalindrome(1) << endl;

    return 0;
}
