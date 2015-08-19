/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: 217.contains_duplicate_II.cpp,v 0.0 2015-08-19 星期三 11:00:24  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   217.contains_duplicate_II.cpp
 * @author zhoujin
 * @date   2015-08-19 星期三 11:00:24
 * @mail   zhoujin1224@gmail.com
 * @brief  Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.
 *
 **/

#include <iostream>
#include <vector>
//#include <map>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int size = nums.size();
        if (size == 0) {
            return false;
        }

        //map<int, int> m;
        unordered_map<int, int> m; //unordered_map faster than map
        for (int i = 0; i < size; ++i) {
            if (m.end() == m.find(nums[i])) {
                m[nums[i]] = i;
            } else {
                if (i - m[nums[i]] <= k) {
                    return true;
                } else {
                    m[nums[i]] = i;
                }
            }
        }

        return false;
    }
};

int main() {
    Solution sol = Solution();
    int a[] = {1, 2, 3, 4, 5, 1, 6, 7, 2, 8, 3, 9};
    vector<int> nums;
    nums.insert(nums.begin(), a, a + sizeof(a) / sizeof(int));

    cout << sol.containsNearbyDuplicate(nums, 4) << endl;
    
    return 0;
}
