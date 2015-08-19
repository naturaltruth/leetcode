/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: contains_duplicate.cpp,v 0.0 2015-08-17 星期一 20:00:25  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   contains_duplicate.cpp
 * @author zhoujin
 * @date   2015-08-17 星期一 20:00:25
 * @mail   zhoujin1224@gmail.com
 * @brief  Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
 *
 **/

#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

class Solution {
  public:
    bool containsDuplicate(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) {
            return false;
        }
        //set<int> s;
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); ++i) {
            if (s.end() != s.find(nums[i])) {
                return true;
            } else {
                s.insert(nums[i]);
            }
        }

        return false;
    }
};

int main() {
    Solution sol = Solution();
    int a[] = {1, 2, 3, 4, 1, 3, 5};
    vector<int> nums;
    nums.insert(nums.begin(), a, a + sizeof(a) / sizeof(int));

    cout << sol.containsDuplicate(nums) << endl;

    return 0;
}
