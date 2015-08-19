/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: valid_anagram.cpp,v 0.0 2015-08-20 星期四 01:38:32  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   valid_anagram.cpp
 * @author zhoujin
 * @date   2015-08-20 星期四 01:38:32
 * @mail   zhoujin1224@gmail.com
 * @brief  Given two strings s and t, write a function to determine if t is an anagram of s.
 *
 * For example,
 * s = "anagram", t = "nagaram", return true.
 * s = "rat", t = "car", return false.
 *
 * Note:
 * You may assume the string contains only lowercase alphabets.
 *
 **/

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    bool isAnagram(string s, string t) {
        int freq[256] = {0};
        int s_len = s.length();
        int t_len = t.length();
        if (s_len != t_len) {
            return false;
        }
        for (int i = 0; i < s_len; ++i) {
            ++freq[s[i]];
            --freq[t[i]];
        }
        for (int i = 0; i < 256; ++i) {
            if (freq[i] != 0) {
                return false;
            }
        }

        return true;
    }

    bool isAnagram2(string s, string t) {
        unordered_map<char, int> m;
        int s_len = s.length();
        int t_len = t.length();
        if (s_len != t_len) {
            return false;
        }
        for (int i = 0; i < s_len; ++i) {
            if (m.end() == m.find(s[i])) {
               m[s[i]]  = 1;
            } else {
                m[s[i]] += 1;
            }
        }
        for (int i = 0; i < t_len; ++i) {
            if (m.end() == m.find(t[i])) {
                return false;
            } else {
                m[t[i]] -= 1;
            }
        }
        for (unordered_map<char, int>::const_iterator iter = m.begin(); iter != m.end(); ++iter) {
            if (iter->second != 0) {
                return false;
            }
        }

        return true;
    }
};


int main() {
    Solution sol = Solution();
    cout << sol.isAnagram("anagram", "nagaram") << endl;
    cout << sol.isAnagram("rat", "car") << endl;

    return 0;
}
