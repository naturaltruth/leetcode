/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: majority_element.cpp,v 0.0 2015-08-05 星期三 17:58:08  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   majority_element.cpp
 * @author zhoujin
 * @date   2015-08-05 星期三 17:58:08
 * @mail   zhoujin1224@gmail.com
 * @brief  Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
 *
 * You may assume that the array is non-empty and the majority element always exist in the array.
 *
 **/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int majorityElement(vector<int>& nums) {
        int ret = nums[0];
        int freq = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (freq == 0) {
                ret = nums[i];
                freq = 1;
                continue;
            }
            if (ret == nums[i]) {
                ++freq;
            } else {
                --freq;
            }
        }

        return ret;
    }
};


int main() {
    Solution sol = Solution();
    int a[] = {1, 1 , 2, 2, 3, 2, 2, 5, 2, 4, 2, 10 ,2 ,11, 2};
    vector<int> vec;
    vec.insert(vec.begin(), a, a + sizeof(a) / sizeof(int));
    cout << sol.majorityElement(vec) << endl;

    return 0;
}
