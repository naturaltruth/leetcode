/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: remove_duplicates_from_sorted_array.cpp,v 0.0 2015-07-16 星期四 07:52:27  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   remove_duplicates_from_sorted_array.cpp
 * @author zhoujin
 * @date   2015-07-16 星期四 07:52:27
 * @mail   zhoujin1224@gmail.com
 * @brief  Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 *
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 *
 * For example,
 * Given input array nums = [1,1,2],
 *
 * Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
 *
 **/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int uniq_size = 1, num = nums[uniq_size - 1];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == num) {
                continue;
            }
            num = nums[i];
            nums[uniq_size] = num;
            ++uniq_size;
        }
        nums.resize(uniq_size);

        return uniq_size;        
    }
};

int main () {
    Solution sol = Solution();
    int a[] = {1, 1, 2, 2, 2, 3, 3, 4, 4, 5};
    vector<int> nums;
    nums.insert(nums.begin(), a, a + sizeof(a) / sizeof(int));

    int size = sol.removeDuplicates(nums);
    cout << size << endl;
    for (int i = 0; i < size; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    int b[] = {1, 1, 1, 1, 1, 1};
    nums.clear();
    nums.insert(nums.begin(), b, b + sizeof(b) / sizeof(int));

    size = sol.removeDuplicates(nums);
    cout << size << endl;
    for (int i = 0; i < size; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
