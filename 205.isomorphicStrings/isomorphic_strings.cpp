/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: isomorphic_strings.cpp,v 0.0 2015-08-10 星期一 17:25:07  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   isomorphic_strings.cpp
 * @author zhoujin
 * @date   2015-08-10 星期一 17:25:07
 * @mail   zhoujin1224@gmail.com
 * @brief  Given two strings s and t, determine if they are isomorphic.
 *
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 *
 * All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
 *
 * For example,
 * Given "egg", "add", return true.
 * Given "foo", "bar", return false.
 * Given "paper", "title", return true.
 *
 * Note:
 * You may assume both s and t have the same length.
 *
 **/

#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
  public:
    bool isIsomorphic(string s, string t) {
        int len = s.length();
        if (len != t.length()) {
            return false;
        }
        const int max_size = 256;
        char map1[max_size] = {0};
        char map2[max_size] = {0};
        for (int i = 0; i < len; ++i) {
            if (map1[s[i]] == 0 && map2[t[i]] == 0) {
                map1[s[i]] = t[i];
                map2[t[i]] = s[i];
                continue;
            } else if (map1[s[i]] == t[i] && map2[t[i]] == s[i])  {
                continue;
            }
            return false;
        }

        return true;
    }

    bool isIsomorphic2(string s, string t) {
        int len1 = s.length();
        int len2 = t.length();
        if (len1 != len2) {
            return false;
        }
        map<char, char> m1, m2;
        for (int i = 0; i < len1; ++i) {
            if (m1.find(s[i]) == m1.end()) {
                m1[s[i]] = t[i];
            } else {
                if (m1[s[i]] != t[i]) return false;
            }
            if (m2.find(t[i]) == m2.end()) {
                m2[t[i]] = s[i];
            } else {
                if (m2[t[i]] != s[i]) return false;
            }
        }

        return true;
    }
};

int main() {
    Solution sol = Solution();
    cout << sol.isIsomorphic("egg", "add") << endl;
    cout << sol.isIsomorphic("foo", "bar") << endl;
    cout << sol.isIsomorphic("paper", "title") << endl;
    cout << sol.isIsomorphic("ab", "aa") << endl;

    return 0;
}
