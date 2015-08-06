/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: reverse_bits.cpp,v 0.0 2015-08-06 星期四 11:26:11  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   reverse_bits.cpp
 * @author zhoujin
 * @date   2015-08-06 星期四 11:26:11
 * @mail   zhoujin1224@gmail.com
 * @brief  Reverse bits of a given 32 bits unsigned integer.
 *
 * For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).
 *
 * Follow up:
 * If this function is called many times, how would you optimize it?
 *
 * Related problem: Reverse Integer
 *
 **/

#include <iostream>

using namespace std;

class Solution {
  public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        int i = 0;
        while (i++ < 32) {
            ret = (ret << 1);
            ret += n % 2;
            n = (n >> 1);
        }

        return ret;
    }
};

int main () {
    Solution sol = Solution();
    cout << sol.reverseBits(43261596) << endl;
    cout << sol.reverseBits(0) << endl;
    cout << sol.reverseBits(1) << endl;
    return 0;
}
