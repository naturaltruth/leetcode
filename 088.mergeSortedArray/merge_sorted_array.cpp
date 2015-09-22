/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: merge_sorted_array.cpp,v 0.0 2015-07-25 星期六 07:34:10  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   merge_sorted_array.cpp
 * @author zhoujin
 * @date   2015-07-25 星期六 07:34:10
 * @mail   zhoujin1224@gmail.com
 * @brief  Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 *
 * Note:
 * You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
 *
 **/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (nums2.empty() || n == 0) {
            return;
        }
        if (nums1.empty() || m == 0) {
            nums1.assign(nums2.begin(), nums2.begin() + n);
            return;
        }
        nums1.resize(m);
        nums2.resize(n);
        int i = n, j = m;
        for (; i > 0 && j > 0;) {
            if (nums2[i - 1] >= nums1[j - 1]) {
                nums1.insert(nums1.begin() + j, nums2[i - 1]);   
                --i;
            } else {
                --j;
            }
        }
        if (i > 0) {
            nums1.insert(nums1.begin(), nums2.begin(), nums2.begin() + i);
        }
    }
};

int main () {
    Solution sol = Solution();
    vector<int> nums1, nums2;
    int a[] = {2, 3, 4, 7, 9, 10};
    nums1.insert(nums1.begin(), a, a + sizeof(a) / sizeof(int));
    int b[] = {1, 2, 5, 6, 11};
    nums2.insert(nums2.begin(), b, b + sizeof(b) / sizeof(int));
    
    sol.merge(nums1, 1, nums2, 1);
    for (int i = 0; i < nums1.size(); ++i) {
        cout << nums1[i] << " ";
    }
    cout << endl;

    return 0;
}
