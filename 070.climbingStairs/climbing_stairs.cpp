/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: climbing_stairs.cpp,v 0.0 2015-07-25 星期六 06:38:55  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   climbing_stairs.cpp
 * @author zhoujin
 * @date   2015-07-25 星期六 06:38:55
 * @mail   zhoujin1224@gmail.com
 * @brief  You are climbing a stair case. It takes n steps to reach to the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 *
 **/

#include <iostream>
#include <vector>

using namespace std;
class Solution {
  public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        vector<int> v;
        v.reserve(n);
        v[0] = 1, v[1] = 2;
        for (int i = 2; i < n; ++i) {
            v[i] = v[i - 2] + v[i - 1];
        }
        return v[n - 1];
    }
    /*
    // Time Limit Exceeded
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
    */
};

int main () {
    Solution sol = Solution();
    cout << sol.climbStairs(4) << endl;

    return 0;
}
