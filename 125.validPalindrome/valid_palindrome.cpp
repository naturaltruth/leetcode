/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: valid_palindrome.cpp,v 0.0 2015-07-28 星期二 20:43:52  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   valid_palindrome.cpp
 * @author zhoujin
 * @date   2015-07-28 星期二 20:43:52
 * @mail   zhoujin1224@gmail.com
 * @brief  Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 *
 * For example,
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 *
 * Note:
 * Have you consider that the string might be empty? This is a good question to ask during an interview.
 *
 * For the purpose of this problem, we define empty string as valid palindrome.
 *
 **/

#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    bool isPalindrome(string s) {
        if (s.empty()) {
            return true;
        }
        //alphanumeric -> isalnum
        //alpha -> isalpha
        //num -> isdigit
        int len = s.length();
        if (1 == len) {
            return true;
        }
        int i = 0, j = len - 1;
        while (i <= j) {
            while (i < len && !isalnum(s[i])) {++i;}
            while (j >= 0 && !isalnum(s[j])) {--j;}
            if (i > j) {
                return true;
            }
            if (s[i] != s[j] && s[i] != s[j] + 32 && s[i] != s[j] - 32) {
                return false;
            } else {
                ++i;
                --j;
            }
        }
        return true;
    }
};


int main () {
    Solution sol = Solution();
    cout << sol.isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << sol.isPalindrome("race a car") << endl;
    cout << sol.isPalindrome("!!!!") << endl;
    cout << sol.isPalindrome("1a2")<< endl;

    return 0;
}
