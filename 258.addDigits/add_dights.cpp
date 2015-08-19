/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: add_dights.cpp,v 0.0 2015-08-17 星期一 20:14:11  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   add_dights.cpp
 * @author zhoujin
 * @date   2015-08-17 星期一 20:14:11
 * @mail   zhoujin1224@gmail.com
 * @brief  Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
 *
 * For example:
 *
 * Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
 *
 * Follow up:
 * Could you do it without any loop/recursion in O(1) runtime?
 *
 * Hint:
 *
 * 1. A naive implementation of the above process is trivial. Could you come up with other methods?
 * 2. What are all the possible results?
 * 3. How do they occur, periodically or randomly?
 * 4. You may find this Wikipedia article useful.
 *
 **/

#include <iostream>

using namespace std;

class Solution {
  public:
    int addDigits(int num) {
        if (num < 10) {
            return num;
        }
        int mod = 0;
        while (num >= 10) {
            mod += num % 10;
            num = num / 10;
            if (num < 10) {
                num += mod;
                mod = 0;
            }
        }

        return num;
    }
}; 

int main () {
    Solution sol = Solution();
    cout << sol.addDigits(38) << endl;
    cout << sol.addDigits(338) << endl;
    cout << sol.addDigits(10) << endl;

    return 0;
}
