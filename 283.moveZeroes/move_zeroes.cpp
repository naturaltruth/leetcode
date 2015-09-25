/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: move_zeroes.cpp,v 0.0 2015-09-23 星期三 14:43:56  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   move_zeroes.cpp
 * @author zhoujin
 * @date   2015-09-23 星期三 14:43:56
 * @mail   zhoujin1224@gmail.com
 * @brief  Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 *
 * For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
 *
 * Note:
 * You must do this in-place without making a copy of the array.
 * Minimize the total number of operations.
 *
 **/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    void moveZeroes(vector<int>& nums) {
        //change the first zero and the first nozero
        int size = nums.size();
        if (0 == size) {
            return;
        }
        int idx = -1; //最靠前的0元素位置
        for (int i = 0; i < size; ++i) {
            if (nums[i] == 0) {
                if (idx < 0) idx = i;
                else continue;
            } else if (nums[i] != 0 && idx >= 0) {
                int tmp = nums[i];
                nums[idx] = tmp;
                nums[i] = 0;
                ++idx;
            } 
        }
    }
};


int main () {
    Solution sol = Solution();
    vector<int> nums;
    int a[] = {0, 1, 0, 3, 12};
    nums.insert(nums.begin(), a, a + sizeof(a) / sizeof(int));

    sol.moveZeroes(nums);
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
    
    int b[] = {1, 0, 0, 0, 3};
    nums.clear();
    nums.insert(nums.begin(), b, b + sizeof(b) / sizeof(int));

    sol.moveZeroes(nums);
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;


    return 0;
}
