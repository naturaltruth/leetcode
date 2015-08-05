/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: factorial_trailing_zeroes.cpp,v 0.0 2015-08-05 星期三 18:28:53  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   factorial_trailing_zeroes.cpp
 * @author zhoujin
 * @date   2015-08-05 星期三 18:28:53
 * @mail   zhoujin1224@gmail.com
 * @brief  Given an integer n, return the number of trailing zeroes in n!.
 *
 * Note: Your solution should be in logarithmic time complexity.
 *
 **/

#include <iostream>

using namespace std;

class Solution {
  public:
    int trailingZeroes(int n) {
        // 计算5的个数
        int ret = 0;
        while (n > 0) {
            n = n / 5;
            ret += n;
        }

        return ret;
    }
};


int main () {
    Solution sol = Solution();
    cout << sol.trailingZeroes(26) << endl;

    return 0;
}
