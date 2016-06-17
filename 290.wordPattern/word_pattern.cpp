/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: word_pattern.cpp,v 0.0 2015-10-09 星期五 22:37:26  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   word_pattern.cpp
 * @author zhoujin
 * @date   2015-10-09 星期五 22:37:26
 * @mail   zhoujin1224@gmail.com
 * @brief  Given a pattern and a string str, find if str follows the same pattern.
 *
 * Examples:
 * pattern = "abba", str = "dog cat cat dog" should return true.
 * pattern = "abba", str = "dog cat cat fish" should return false.
 * pattern = "aaaa", str = "dog cat cat dog" should return false.
 * pattern = "abba", str = "dog dog dog dog" should return false.
 * Notes:
 * patterncontains only lowercase alphabetical letters, and str contains words separated by a single space. Each word in str contains only lowercase alphabetical letters.
 * Both pattern and str do not have leading or trailing spaces.
 * Each letter in pattern must map to a word with length that is at least 1.
 *
 **/

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Solution {
  public:
    bool wordPattern(string pattern, string str) {
        if (pattern.empty() && str.empty()) return true;
        if (pattern.empty() || str.empty()) return false;
        vector<string> substr_vec;
        string sub = "";
        for (int i = 0; i < str.length(); ++i) {
            if (str[i] == ' ') {
                substr_vec.push_back(sub);
                sub = "";
            } else {
                sub.append(1, str[i]);
            }
        }
        substr_vec.push_back(sub);
        if (substr_vec.size() != pattern.length()) return false;

        map<string, char> m1;
        map<char, string> m2;
        for (int i = 0; i < substr_vec.size(); ++i) {
            sub = substr_vec[i];
            if (m1.find(sub) != m1.end()) {
                if (m1[sub] != pattern[i]) return false;
            } else {
                m1[sub] = pattern[i];
            }
        }
        for (int i = 0; i < pattern.length(); ++i) {
            char sub = pattern[i];
            if (m2.find(sub) != m2.end()) {
                if (m2[sub] != substr_vec[i]) return false;
            } else {
                m2[sub] = substr_vec[i];
            }
        }

        return true;
    }
};

int main() {
    Solution sol = Solution();
    cout << sol.wordPattern("abba", "dog cat cat dog") << endl;
    cout << sol.wordPattern("abba", "dog cat cat fish") << endl;
    cout << sol.wordPattern("aaaa", "dog cat cat dog") << endl;
    cout << sol.wordPattern("abba", "dog dog dog dog") << endl;

    return 0;
}
