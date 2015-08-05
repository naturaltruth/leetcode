/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: excel_sheet_column_number.cpp,v 0.0 2015-08-05 星期三 18:13:37  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   excel_sheet_column_number.cpp
 * @author zhoujin
 * @date   2015-08-05 星期三 18:13:37
 * @mail   zhoujin1224@gmail.com
 * @brief  Related to question 168.Excel Sheet Column Title
 *
 * Given a column title as appear in an Excel sheet, return its corresponding column number.
 *
 * For example:
 *
 *     A -> 1
 *     B -> 2
 *     C -> 3
 *     ...
 *     Z -> 26
 *     AA -> 27
 *     AB -> 28 
 *
 **/

#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    int titleToNumber(string s) {
        int ret = 0;
        for (int i = 0; i < s.length(); ++i) {
            ret = ret * 26 + (s[i] - 'A' + 1) ;
        }

        return ret;
    }
};


int main() {
    Solution sol = Solution();
    cout << sol.titleToNumber("HH") << endl;

    return 0;
}
