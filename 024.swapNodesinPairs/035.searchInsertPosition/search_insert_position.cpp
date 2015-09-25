/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: search_insert_position.cpp,v 0.0 2015-09-25 星期五 17:59:39  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   search_insert_position.cpp
 * @author zhoujin
 * @date   2015-09-25 星期五 17:59:39
 * @mail   zhoujin1224@gmail.com
 * @brief  Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 *
 * You may assume no duplicates in the array.
 *
 * Here are few examples.
 * [1,3,5,6], 5 → 2
 * [1,3,5,6], 2 → 1
 * [1,3,5,6], 7 → 4
 * [1,3,5,6], 0 → 0
 *
 **/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty()) return 0;
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            if (nums[i] >= target) {
                return i;
            } else {
                continue;
            }
        }

        return size;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> nums;
    int a[] = {1, 3, 5, 6};
    nums.insert(nums.begin(), a, a + sizeof(a) / sizeof(int));

    cout << sol.searchInsert(nums, 5) << endl;
    cout << sol.searchInsert(nums, 2) << endl;
    cout << sol.searchInsert(nums, 7) << endl;
    cout << sol.searchInsert(nums, 0) << endl;
    
    return 0;
}
