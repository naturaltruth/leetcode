/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: happy_number.cpp,v 0.0 2015-08-06 星期四 14:37:37  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   happy_number.cpp
 * @author zhoujin
 * @date   2015-08-06 星期四 14:37:37
 * @mail   zhoujin1224@gmail.com
 * @brief  Write an algorithm to determine if a number is "happy".
 *
 * A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
 *
 * Example: 19 is a happy number
 *
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 *
 **/

#include <iostream>
#include <map>

using namespace std;

class Solution {
  public:
    bool isHappy(int n) {
        if (n == 1) {
            return true;
        }

        map<int, bool> appear;
        appear[n] = true;
        while (n != 1) {
            n = loop(n);
            if (appear.end() != appear.find(n)) {
                return false;
            }
            appear[n] = true;
        }

        return true;
    }

    // 在迭代过程一定会出现个位数的情形
    bool isHappy2(int n) {
        while (n > 9) {
            n = loop(n);
        }
        // 1 - 9 中仅有 1 和 7 满足happyNumber的条件
        if (n != 1 && n != 7) {
            return false;

        }

        return true;
    }

  private:
    int loop(int n) {
        int ret = 0;
        while (n > 0) {
            int mod = n % 10;
            ret += mod * mod;
            n = n / 10;
        }
        return ret;
    }
};


int main () {
    Solution sol = Solution();
    cout << sol.isHappy(1) << endl;
    cout << sol.isHappy(2) << endl;
    cout << sol.isHappy(3) << endl;
    cout << sol.isHappy(4) << endl;
    cout << sol.isHappy(5) << endl;
    cout << sol.isHappy(6) << endl;
    cout << sol.isHappy(7) << endl;
    cout << sol.isHappy(8) << endl;
    cout << sol.isHappy(9) << endl;
    cout << sol.isHappy(1111112) << endl;
    cout << sol.isHappy(19) << endl;
    cout << sol.isHappy(13) << endl;
    return 0;
}
