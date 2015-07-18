/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: remove_element.cpp,v 0.0 2015-07-18 星期六 07:54:17  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   remove_element.cpp
 * @author zhoujin
 * @date   2015-07-18 星期六 07:54:17
 * @mail   zhoujin1224@gmail.com
 * @brief  Given an array and a value, remove all instances of that value in place and return the new length.
 *
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 *
 **/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) {
            return 0;
        }
        int nums_size = nums.size();
        int ret_size = nums_size;
        for (int i = nums_size - 1; i >= 0; --i) {
            if (nums[i] == val) {
                int tmp = nums[ret_size - 1];
                nums[ret_size - 1] = val;
                nums[i] = tmp; 
                --ret_size;
            }
        }
        nums.resize(ret_size);

        return ret_size;
    }
};

int main () {
    Solution sol = Solution();
    vector<int> nums;
    int a[10] = {1, 2, 3, 3, 2, 4, 5, 6, 7, 6};
    nums.insert(nums.begin(), a, a + 10);
    cout << sol.removeElement(nums, 6) << endl;
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
