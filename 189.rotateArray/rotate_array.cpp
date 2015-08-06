/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: rotate_array.cpp,v 0.0 2015-08-05 星期三 20:07:55  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   rotate_array.cpp
 * @author zhoujin
 * @date   2015-08-05 星期三 20:07:55
 * @mail   zhoujin1224@gmail.com
 * @brief  Rotate an array of n elements to the right by k steps.
 *
 * For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
 *
 * Note:
 * Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
 *
 * [show hint]
 *
 * Hint:
 * Could you do it in-place with O(1) extra space?
 * Related problem: Reverse Words in a String II
 *
 **/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        if (len == 0 || k % len == 0) {
            return;
        }
        k = k % len;
        rotateVector(nums, 0, len - 1);
        rotateVector(nums, 0, k - 1);
        rotateVector(nums, k, len - 1);
    }

    // this solution is slow with insert vector
    void rotate2(vector<int>& nums, int k) {
        int len = nums.size();
        if (len == 0 || k % len == 0) {
            return;
        }
        k = k % len;
        nums.insert(nums.begin(), nums.begin() + len - k, nums.end());
        nums.resize(len);
    }

  private:
    void rotateVector(vector<int>& nums, int begin, int end) {
        for (int i = 0; i < (end - begin + 1) / 2; ++i) {
            int tmp = nums[begin + i];
            nums[begin + i] = nums[end - i];
            nums[end - i] = tmp;
        }
    }
};

int main () {
    Solution sol = Solution();
    int a[] = {1,2,3,4,5,6,7};
    vector<int> nums;
    nums.insert(nums.begin(), a, a + sizeof(a) / sizeof(int));
    sol.rotate(nums, 10);

    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}
