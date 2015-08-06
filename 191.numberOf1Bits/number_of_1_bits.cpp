/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: number_of_1_bits.cpp,v 0.0 2015-08-06 星期四 11:46:22  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   number_of_1_bits.cpp
 * @author zhoujin
 * @date   2015-08-06 星期四 11:46:22
 * @mail   zhoujin1224@gmail.com
 * @brief  Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).
 *
 * For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
 *
 **/

#include <iostream>

using namespace std;

class Solution {
  public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        while (n > 0) {
            ++ret;
            n = (n & (n - 1));
        }
        
        return ret;
    }

    int hammingWeight2(uint32_t n) {
        int ret = 0;
        while (n > 0) {
            if (n % 2 == 1) {
                ++ret;
            }
            n = (n >> 1);
        }

        return ret;
    }
};

int main () {
    Solution sol = Solution();
    cout << sol.hammingWeight(9) << endl;
    return 0;
}
