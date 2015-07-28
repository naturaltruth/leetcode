/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: pascals_triangle_II.cpp,v 0.0 2015-07-28 星期二 20:06:29  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   pascals_triangle_II.cpp
 * @author zhoujin
 * @date   2015-07-28 星期二 20:06:29
 * @mail   zhoujin1224@gmail.com
 * @brief  Given an index k, return the kth row of the Pascal's triangle.
 *
 * For example, given k = 3,
 * Return [1,3,3,1].
 *
 * Note:
 * Could you optimize your algorithm to use only O(k) extra space?
 *
 **/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> getRow(int rowIndex) {
        vector<int> vec;
        vec.reserve(rowIndex + 1);
        vec.push_back(1);
        for (int i = 1; i <= rowIndex; ++i) {
            int prev = 0, curr = 0;
            for (int j = 0; j < vec.size(); ++j) {
                if (j == 0) prev = 0;
                else prev = curr;
                curr = vec[j];
                vec[j] = prev + curr;
            }
            vec.push_back(1);
        }
        return vec;
    }
};

int main () {
    Solution sol = Solution();
    vector<int> vec = sol.getRow(1);

    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}
