/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: summary_ranges.cpp,v 0.0 2015-08-20 星期四 00:23:50  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   summary_ranges.cpp
 * @author zhoujin
 * @date   2015-08-20 星期四 00:23:50
 * @mail   zhoujin1224@gmail.com
 * @brief  Given a sorted integer array without duplicates, return the summary of its ranges.
 *
 * For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
 *
 **/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
  public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> vec;
        int size = nums.size();
        if (size == 0) {
            return vec;
        }

        int start = nums[0], end = nums[0];
        for (int i = 1; i < size; ++i) {
            if (nums[i] == end + 1) {
                end = nums[i];
            } else {
                vec.push_back(format(start, end));
                start = nums[i];
                end = nums[i];
            }
        }
        vec.push_back(format(start, end));

        return vec;
    }
  
  private:
    string format(int start, int end) {
        char tmp[32];
        tmp[31] = '\0';
        if (start == end) {
            sprintf(tmp, "%d", start);
        } else {
            sprintf(tmp, "%d->%d", start, end);
        }
        return string(tmp);
    }
  
  public:
    vector<string> summaryRanges2(vector<int>& nums) {
        vector<string> vec;
        int size = nums.size();
        if (size == 0) {
            return vec;
        }

        string s = "";
        char tmp[32];
        tmp[31] = '\0';
        int prev = 0, start = 0;
        for (int i = 0; i < size; ++i) {
            if (nums[i] - prev != 1 && !s.empty()) {
                if (start == prev) {
                    vec.push_back(s);
                } else {
                    sprintf(tmp, "%d", prev);
                    s += "->" + string(tmp);
                    vec.push_back(s);
                }
                s = "";
            }
            if (s.empty()) {
                sprintf(tmp, "%d", nums[i]);
                s = string(tmp);
                start = nums[i];
                prev = nums[i];
                continue;
            }
            prev = nums[i];
        }
        if (prev == start) {
            vec.push_back(s);
        } else {
            sprintf(tmp, "%d", prev);
            s += "->" + string(tmp);
            vec.push_back(s);
        }

        return vec;
    }
};

int main() {
    Solution sol = Solution();
    int a[] = {0, 1, 2, 4, 5, 7};
    //int a[] = {0, 1, 2, 4, 5, 7, 8, 9};
    //int a[] = {-1};
    //int a[] = {1, 3};
    vector<int> nums;
    nums.insert(nums.begin(), a, a + sizeof(a) / sizeof(int));
    vector<string> vec;
    vec = sol.summaryRanges(nums);

    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << endl;
    }

    return 0;
}
