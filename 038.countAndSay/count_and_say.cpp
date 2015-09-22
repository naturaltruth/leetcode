/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: count_and_say.cpp,v 0.0 2015-07-19 星期日 00:29:54  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   count_and_say.cpp
 * @author zhoujin
 * @date   2015-07-19 星期日 00:29:54
 * @mail   zhoujin1224@gmail.com
 * @brief  The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 *
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * Given an integer n, generate the nth sequence.
 *
 * Note: The sequence of integers will be represented as a string.
 *
 **/

#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    string countAndSay(int n) {
        if (n == 0) {
            return "";
        }
        if (n == 1) {
            return "1";
        }

        string ret = "1";
        for (int i = 1; i < n; ++i) {
            ret = getNext(ret);
        }

        return ret;
    }

    string getNext(string s) {
        string ret = "";
        char num = s[0];
        int freq = 1; 
        for (int i = 1; i < s.length(); ++i) {
            if (s[i] != num) {
                ret.push_back(char(freq + '0'));
                ret.push_back(num);
                num = s[i];
                freq = 1;
            } else {
                ++freq;
            }
        }
        ret.push_back(freq + '0');
        ret.push_back(num);
        return ret;
    }
};

int main () {
    Solution sol = Solution();
    cout << sol.countAndSay(10) << endl;

    return 0;
}
