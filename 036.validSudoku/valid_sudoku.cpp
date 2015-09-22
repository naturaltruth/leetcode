/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: valid_sudoku.cpp,v 0.0 2015-07-18 星期六 09:21:53  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   valid_sudoku.cpp
 * @author zhoujin
 * @date   2015-07-18 星期六 09:21:53
 * @mail   zhoujin1224@gmail.com
 * @brief  Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
 *
 * The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
 *
 * A partially filled sudoku which is valid.
 *
 * Note:
 * A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
 *
 * There are just 3 rules to Sudoku.
 * 1. Each row must have the numbers 1-9 occuring just once.
 * 2. Each column must have the numbers 1-9 occuring just once.
 * 3. And the numbers 1-9 must occur just once in each of the 9 sub-boxes of the grid.
 *
 **/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    bool isValidSudoku(vector<vector<char> >& board) {
        const int size = 9;
        bool row_flag[size][size] = {false};
        bool col_flag[size][size] = {false};
        bool subbox_flag[size][size] = {false};
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                int num = board[i][j] - '0';
                if (num > 9 || num < 1) {
                    continue;
                }
                int idx = num - 1;
                if (row_flag[i][idx]) {
                    return false;
                }
                row_flag[i][idx] = true;
                if (col_flag[j][idx]) {
                    return false;
                }
                col_flag[j][idx] = true;
                // 划分subbox
                int subbox_idx = (i / 3) * 3 + (j / 3);
                if (subbox_flag[subbox_idx][idx]) {
                    return false;
                }
                subbox_flag[subbox_idx][idx] = true;
            }
        }

        return true;
    }
};


int main () {
    Solution sol = Solution();
    vector<vector<char> > board;
    char a1[] = {'4', '6', '3', '7'};
    vector<char> v1(a1, a1 + sizeof(a1) / sizeof(char));
    board.push_back(v1);
    char a2[] = {'2', '5', '9', '4', '6'};
    vector<char> v2(a2, a2 + sizeof(a2) / sizeof(char));
    board.push_back(v2);
    char a3[] = {'7', '8', '1', '3', '5', '9'};
    vector<char> v3(a3, a3 + sizeof(a3) / sizeof(char));
    board.push_back(v3);
    
    cout << sol.isValidSudoku(board) << endl;

    return 0;
}
