/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: ugly_number.cpp,v 0.0 2015-08-20 星期四 02:00:48  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   ugly_number.cpp
 * @author zhoujin
 * @date   2015-08-20 星期四 02:00:48
 * @mail   zhoujin1224@gmail.com
 * @brief  Write a program to check whether a given number is an ugly number.
 *
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
 *
 * Note that 1 is typically treated as an ugly number.
 *
 **/

#include <iostream>

using namespace std;

class Solution {
  public:
    bool isUgly(int num) {
        if (num <= 0) {
            return false;
        }
        while (num % 2 == 0) num = num / 2;
        while (num % 3 == 0) num = num / 3;
        while (num % 5 == 0) num = num / 5;

        return num == 1 ? true : false;
    }
};

int main() {
    Solution sol = Solution();

    cout << sol.isUgly(1) << endl;
    cout << sol.isUgly(25) << endl;
    cout << sol.isUgly(21) << endl;

    return 0;
}
