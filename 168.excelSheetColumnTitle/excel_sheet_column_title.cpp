/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: excel_sheet_column_title.cpp,v 0.0 2015-08-05 星期三 17:24:00  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   excel_sheet_column_title.cpp
 * @author zhoujin
 * @date   2015-08-05 星期三 17:24:00
 * @mail   zhoujin1224@gmail.com
 * @brief  Given a positive integer, return its corresponding column title as appear in an Excel sheet.
 *
 * For example:
 *
 *     1 -> A
 *     2 -> B
 *     3 -> C
 *     ...
 *     26 -> Z
 *     27 -> AA
 *     28 -> AB 
 *
 **/

#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    string convertToTitle(int n) {
        if (n <= 0) {
            return "";
        }
        const char title[26] = {
            'A', 'B', 'C', 'D', 'E', 'F', 'G',
            'H', 'I', 'J', 'K', 'L', 'M', 'N',
            'O', 'P', 'Q', 'R', 'S', 'T',
            'U', 'V', 'W', 'X', 'Y', 'Z'
        };
        string ret = "";
        while (n > 0) {
            int idx = (n - 1) % 26;
            ret.insert(ret.begin(), title[idx]);
            n = (n - idx) / 26;
        }

        return ret;
    }
};


int main() {
    Solution sol = Solution();
    cout << sol.convertToTitle(26) << endl;
    cout << sol.convertToTitle(27) << endl;
    cout << sol.convertToTitle(52) << endl;

    return 0;
}

