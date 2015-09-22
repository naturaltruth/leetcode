/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: first_bad_version.cpp,v 0.0 2015-09-10 星期四 17:48:52  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   first_bad_version.cpp
 * @author zhoujin
 * @date   2015-09-10 星期四 17:48:52
 * @mail   zhoujin1224@gmail.com
 * @brief  You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.
 *
 * Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.
 *
 * You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.
 *
 **/

#include <iostream>

using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
  public:
    int firstBadVersion(int n) {
        if (n <= 1) return n;
        int low = 1, high = n;
        while (low <= high) {
            int mid = low + ((high - low) >> 1); 
            if (isBadVersion(mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main() {
    return 0;
}
