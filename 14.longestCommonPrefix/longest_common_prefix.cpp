/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: longest_common_prefix.cpp,v 0.0 2015-07-16 星期四 06:59:58  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   longest_common_prefix.cpp
 * @author zhoujin
 * @date   2015-07-16 星期四 06:59:58
 * @mail   zhoujin1224@gmail.com
 * @brief  Write a function to find the longest common prefix string amongst an array of strings.
 *
 **/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
  public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return string("");
        }
        if (1 == strs.size()) {
            return strs[0];
        }
        string ret = "";
        int min_size = strs[0].length();
        for (int i = 0; i < min_size;++i) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); ++j) {
                if (strs[j].length() < min_size) {
                    min_size = strs[j].length();
                }
                if (strs[j].length() < i || strs[j][i] != c) {
                    return ret;
                }
            }
            ret.push_back(c);
        }
        return ret;        
    }
};

int main () {
    Solution sol = Solution();
    vector<string> strs;
    strs.push_back("aaaaa");
    strs.push_back("aaabb");
    strs.push_back("aabc");
    cout << sol.longestCommonPrefix(strs) << endl;

    return 0;
}
