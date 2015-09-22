/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: roman_to_integer.cpp,v 0.0 2015-07-14 星期二 00:08:19  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   roman_to_integer.cpp
 * @author zhoujin
 * @date   2015-07-14 星期二 00:08:19
 * @mail   zhoujin1224@gmail.com
 * @brief  Given a roman numeral, convert it to an integer.
 * Input is guaranteed to be within the range from 1 to 3999.
 *
 * 1、相同的数字连写，所表示的数等于这些数字相加得到的数，如：Ⅲ = 3；
 * 2、小的数字在大的数字的右边，所表示的数等于这些数字相加得到的数， 如：Ⅷ = 8；Ⅻ = 12；
 * 3、小的数字，（限于Ⅰ、X 和C）在大的数字的左边，所表示的数等于大数减小数得到的数，如：Ⅳ= 4；Ⅸ= 9；
 **/

#include <iostream>

using namespace std;

class Solution {
  public:
    int romanToInt(string s) {
        if (s.empty()) {
            return 0;
        }
        int ret = oneCharMap(s[0]);
        for (int i = 1; i < s.length(); ++i) {
            int prev = oneCharMap(s[i - 1]);
            int cur = oneCharMap(s[i]);
            if (prev < cur) {
                ret = ret + cur - prev - prev;
            } else {
                ret += cur;
            }
        }
        return ret;
    }

  private:
    inline int oneCharMap(char c) {
        switch(c) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
    }
};

int main () {
    Solution sol = Solution();
    cout << sol.romanToInt("IV") << endl;
    cout << sol.romanToInt("VII") << endl;

    return 0;
}
