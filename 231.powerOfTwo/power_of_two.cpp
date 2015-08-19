/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: power_of_two.cpp,v 0.0 2015-08-20 星期四 01:17:52  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   power_of_two.cpp
 * @author zhoujin
 * @date   2015-08-20 星期四 01:17:52
 * @mail   zhoujin1224@gmail.com
 * @brief  Given an integer, write a function to determine if it is a power of two.
 *
 **/

#include <iostream>

using namespace std;

class Solution {
  public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }

        return !(n & (n - 1));
    }

    bool isPowerOfTwo2(int n) {
        if (n <= 0) {
            return false;
        }
        while (n > 1) {
            if (n & 0x1) {
                return false;
            }
            n = n >> 1;
        }

        return true;
    }
};

int main() {
    Solution sol = Solution();
    cout << sol.isPowerOfTwo(2) << endl;
    cout << sol.isPowerOfTwo(3) << endl;
    cout << sol.isPowerOfTwo(256) << endl;

    return 0;
}
