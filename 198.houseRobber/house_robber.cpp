/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: house_robber.cpp,v 0.0 2015-08-06 星期四 11:54:31  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   house_robber.cpp
 * @author zhoujin
 * @date   2015-08-06 星期四 11:54:31
 * @mail   zhoujin1224@gmail.com
 * @brief  You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
 *
 * Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
 *
 **/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        if (len == 1) return nums[0];

        vector<int> sum(len + 1, 0);
        sum[0] = 0;
        sum[1] = nums[0];
        for (int i = 1; i < len; ++i) {
            sum[i + 1] = sum[i - 1] + nums[i] > sum[i] ? sum[i - 1] + nums[i] : sum[i];
        }

        return sum[len];
    }
};


int main () {
    Solution sol = Solution();
    int a[] = {8, 1, 7, 9, 2, 7, 9, 1};
    vector<int> nums;
    nums.insert(nums.begin(), a, a + sizeof(a) / sizeof(int));
    cout << sol.rob(nums) << endl;

    return 0;
}
