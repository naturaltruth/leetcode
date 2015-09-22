/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: add_binary.cpp,v 0.0 2015-07-23 星期四 08:45:16  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   add_binary.cpp
 * @author zhoujin
 * @date   2015-07-23 星期四 08:45:16
 * @mail   zhoujin1224@gmail.com
 * @brief  Given two binary strings, return their sum (also a binary string).
 *
 * For example,
 * a = "11"
 * b = "1"
 * Return "100".
 *
 **/

#include <iostream>

using namespace std;

class Solution {
  public:
    string addBinary(string a, string b) {
        if (a.empty()) {
            return b;
        }
        if (b.empty()) {
            return a;
        }
        string ret = "";
        int a_len = a.length(), b_len = b.length();
        int i = a_len - 1, j = b_len - 1;
        int carry = 0;
        for (; i >=0 && j >=0; --i, --j) {
            char sum = (a[i] - '0' + b[j] - '0' + carry) % 2 + '0';
            carry = (a[i] - '0' + b[j] - '0' + carry) / 2;
            ret.insert(0, 1, sum);
        }
        while (i >= 0) {
            char sum = (a[i] - '0' + carry) % 2 + '0';
            carry = (a[i] - '0' + carry) / 2;
            ret.insert(0, 1, sum);
            --i;
        }
        while (j >= 0) {
            char sum = (b[j] - '0' + carry) % 2 + '0';
            carry = (b[j] - '0' + carry) / 2;
            ret.insert(0, 1, sum);
            --j;
        }
        if (carry != 0) {
            ret.insert(0, 1, carry + '0');
        }

        return ret;
    }
};

int main () {
    Solution sol = Solution();
    cout << sol.addBinary("11", "101") << endl;
    return 0;
}
