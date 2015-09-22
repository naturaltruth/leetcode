/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: zig_zag_conversion.cpp,v 0.0 2015-08-11 星期二 16:54:14  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   zig_zag_conversion.cpp
 * @author zhoujin
 * @date   2015-08-11 星期二 16:54:14
 * @mail   zhoujin1224@gmail.com
 * @brief  The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows
 * like this: (you may want to display this pattern in a fixed font for better legibility)
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a number of rows:
 * string convert(string text, int nRows);
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

 * nRows = 3
 * o       o       o
 * ↓     ↗ ↓     ↗ ↓
 * o   o   o   o   o
 * ↓ ↗     ↓ ↗     ↓
 * o       o       o

 * nRows = 4
 * o           o           o
 * ↓         ↗ ↓         ↗ ↓
 * o       o   o       o   o
 * ↓     ↗     ↓     ↗     ↓
 * o   o       o   o       o
 * ↓ ↗         ↓ ↗         ↓
 * o           o           o
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *
 **/

#include <iostream>

using namespace std;

class Solution {
  public:
    string convert(string s, int numRows) {
        int len = s.length();
        if (len == 0 || numRows <=1) return s;

        string ret = "";
        for (int row = 0; row < len && row < numRows; ++row) {
            int idx = row;
            ret += s[idx];

            for (int col = 1; idx < len; ++col) {
                if (row == 0 || row == numRows - 1) {
                    idx += 2 * numRows - 2;
                } else {
                    if (col & 0x01) idx += 2 * (numRows - row - 1);
                    else idx += 2 * row;
                }
                if (idx < len) ret += s[idx];
            }
        }

        return ret;
    }
};

int main() {
    Solution sol = Solution();
    cout << sol.convert("PAYPALISHIRING", 3) << endl;

    return 0;
}
