/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: length_of_last_word.cpp,v 0.0 2015-07-23 星期四 08:20:40  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   length_of_last_word.cpp
 * @author zhoujin
 * @date   2015-07-23 星期四 08:20:40
 * @mail   zhoujin1224@gmail.com
 * @brief  Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 *
 * If the last word does not exist, return 0.
 *
 * Note: A word is defined as a character sequence consists of non-space characters only.
 *
 * For example, 
 * Given s = "Hello World",
 * return 5.
 *
 **/

#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    int lengthOfLastWord(string s) {
        if (s.empty()) {
            return 0;
        }
        int len = s.length();
        int i = len - 1;
        for (; i >= 0; --i) {
            if (s[i] != ' ') {
                break;
            }
        }
        if (i < 0) {
            return 0;
        }
        int ret = 0;
        for (; i >= 0; --i) {
            if(s[i] != ' ') {
                ++ret;
            } else {
                break;
            }
        }
        return ret;
    }
};

int main() {
    Solution sol = Solution();
    cout << sol.lengthOfLastWord("       ") << endl;;
    cout << sol.lengthOfLastWord("a       ") << endl;;
    cout << sol.lengthOfLastWord("a    bbb  ") << endl;;

    return 0;
}
