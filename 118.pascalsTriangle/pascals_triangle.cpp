/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: pascals_triangle.cpp,v 0.0 2015-07-28 星期二 19:45:04  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   pascals_triangle.cpp
 * @author zhoujin
 * @date   2015-07-28 星期二 19:45:04
 * @mail   zhoujin1224@gmail.com
 * @brief  Given numRows, generate the first numRows of Pascal's triangle.
 *
 * For example, given numRows = 5,
 * Return
 *
 * [
 *      [1],
 *     [1,1],
 *    [1,2,1],
 *   [1,3,3,1],
 *  [1,4,6,4,1]
 * ]
 *
 **/

#include <iostream>
#include <vector>

using namespace std;
class Solution {
  public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > vec_vec;
        if (numRows == 0) {
            return vec_vec;
        }
        vec_vec.reserve(numRows);
        vector<int> vec(1, 1);
        vec_vec.push_back(vec);
        for (int i = 1; i < numRows; ++i) {
            vec.clear();
            vec.reserve(i + 1);
            vec.push_back(1);
            int size = vec_vec[i - 1].size();
            for (int j = 1; j < size; ++j) {
               vec.push_back(vec_vec[i - 1][j - 1] + vec_vec[i - 1][j]); 
            }
            vec.push_back(1);
            vec_vec.push_back(vec);
        }

        return vec_vec;
    }
};

int main () {
    Solution sol = Solution();
    vector<vector<int> > vec_vec = sol.generate(5);

    for (int i = 0; i < vec_vec.size(); ++i) {
        for (int j = 0; j < vec_vec[i].size(); ++j) {
            cout << vec_vec[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
