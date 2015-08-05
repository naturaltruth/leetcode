/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: compare_version_numbers.cpp,v 0.0 2015-08-01 星期六 10:53:31  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   compare_version_numbers.cpp
 * @author zhoujin
 * @date   2015-08-01 星期六 10:53:31
 * @mail   zhoujin1224@gmail.com
 * @brief  Compare two version numbers version1 and version2.
 * If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
 *
 * You may assume that the version strings are non-empty and contain only digits and the . character.
 * The . character does not represent a decimal point and is used to separate number sequences.
 * For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
 *
 * Here is an example of version numbers ordering:
 *
 * 0.1 < 1.1 < 1.2 < 13.37
 *
 **/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    int compareVersion(string version1, string version2) {
        vector<int> vec1, vec2;
        vec1 = versionConvertToVector(version1);
        vec2 = versionConvertToVector(version2);
        int i = 0;
        for (; i < vec1.size() && i < vec2.size(); ++i) {
            if (vec1[i] > vec2[i]) {
                return 1;
            } else if (vec1[i] < vec2[i]) {
                return -1;
            }
        }
        while (i < vec1.size()) {
            if (vec1[i] > 0) {
                return 1;
            }
            ++i;
        }
        while (i < vec2.size()) {
            if (vec2[i] > 0) {
                return -1;
            }
            ++i;
        }
        return 0;
    }
    
  private:
    vector<int> versionConvertToVector(string version) {
        vector<int> vec;
        int len = version.length();
        int ver = 0;
        for (int i = 0; i < len; ++i) {
            if (version[i] == '.') {
                vec.push_back(ver);
                ver = 0;
                continue;
            }
            ver += ver * 10 + version[i] - '0';
        } 
        vec.push_back(ver);
        return vec;
    }
};


int main () {
    Solution sol = Solution();
    cout << sol.compareVersion("1.11.22", "1.12.22") << endl;
    cout << sol.compareVersion("1.11.00", "1.11") << endl;

    return 0;
}
