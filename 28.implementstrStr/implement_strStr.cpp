/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: implement_strStr.cpp,v 0.0 2015-07-18 星期六 08:11:27  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   implement_strStr.cpp
 * @author zhoujin
 * @date   2015-07-18 星期六 08:11:27
 * @mail   zhoujin1224@gmail.com
 * @briefa Implement strStr().
 *
 * Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 *
 * Update (2014-11-02):
 * The signature of the function had been updated to return the index instead of the pointer. If you still see your function signature returns a char * or String, please click the reload button  to reset your code definition.
 *
 **/

#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        if (haystack.empty()) {
            return -1;
        }
        int len1 = haystack.length();
        int len2 = needle.length();
        int i = 0, j = 0;
        for (; i < len1 && j < len2; ++i) {
            if (haystack[i] == needle[j]) {
                ++j;
            } else {
                i = i - j;
                j = 0;
            } 
        }
        if (j < len2) {
            return -1;
        }

        return i - len2;
    }
};

int main () {
    Solution sol = Solution();
    string haystack = "aaabbcc";
    string needle = "abb";
    cout << sol.strStr(haystack, needle) << endl;

    return 0;
}
