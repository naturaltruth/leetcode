/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: divide_two_integer.cpp,v 0.0 2015-10-09 星期五 23:30:48  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   divide_two_integer.cpp
 * @author zhoujin
 * @date   2015-10-09 星期五 23:30:48
 * @mail   zhoujin1224@gmail.com
 * @brief  Divide two integers without using multiplication, division and mod operator.
 *
 * If it is overflow, return MAX_INT.
 *
 **/

#include <iostream>
#include <limits>

using namespace std;

class Solution {
  public:
    int divide(int dividend, int divisor) {
        if (divisor == 0) return INT_MAX;
        if (dividend == 0) return 0;
        int flag1 = true, flag2 = true;
        unsigned int u_dividend = dividend;
        if (dividend < 0) {
            flag1 = false;
            u_dividend = 0 - dividend;
        }
        unsigned int u_divisor = divisor;
        if (divisor < 0) {
            flag2 = false;
            u_divisor = 0 - divisor;
        }
        if (u_dividend < u_divisor) return 0;
        unsigned int ret = 0, tmp1 = u_dividend, tmp2 = u_divisor;
        int part = 1;
        while (tmp2 <= (tmp1 >> 1)) {
            tmp2 = (tmp2 << 1);
            part = (part << 1);
            if (tmp2 >= (tmp1 >> 1)) {
                ret += part;
                part = 1;
                tmp1 -= tmp2;
                tmp2 = u_divisor;
            }
        }
        if (tmp1 >= tmp2) {
            ret += 1;
        }
        bool sign = flag1 ^ flag2;
        if ((ret > INT_MAX && !sign) || (ret - 1 > INT_MAX && sign)) {
            return INT_MAX;
        }
        ret = (sign ? 0 - ret : ret);
        return (int)ret;
    }
};


int main() {
    //cout << "-7 / -2 = " << -7 / -2 << endl; // 3
    //cout << "7 / -2 = " << 7 / -2 << endl; // -3
    //cout << "-7 / 2 = " << -7 / 2 << endl; // -3
    //cout << " 1 / 2 = " << 1 /2 << endl; 
    //cout << " -1 / 2 = " << -1 /2 << endl; 

    Solution sol = Solution();
    cout << sol.divide(-7, 2) << endl;
    cout << sol.divide(-8, 2) << endl;
    cout << sol.divide(10, 2) << endl;
    cout << sol.divide(9, 2) << endl;
    cout << sol.divide(0, 2) << endl;
    cout << sol.divide(0, 0) << endl;
    cout << sol.divide(102400000, 2) << endl;
    cout << sol.divide(INT_MAX, 1) << endl;
    cout << sol.divide(INT_MIN, -1) << endl;
    cout << sol.divide(INT_MIN, 1) << endl;

    return 0;
}

