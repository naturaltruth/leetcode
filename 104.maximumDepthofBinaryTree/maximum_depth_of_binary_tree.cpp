/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: maximum_depth_of_binary_tress.cpp,v 0.0 2015-07-07 星期二 10:07:12  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   maximum_depth_of_binary_tress.cpp
 * @author zhoujin
 * @date   2015-07-07 星期二 10:07:12
 * @mail   zhoujin1224@gmail.com
 * @brief  Given a binary tree, find its maximum depth.
 *
 * The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 *
 **/

#include <iostream>

using namespace std;

/**
* Definition for a binary tree node.
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    int maxDepth(TreeNode* root) {
        if (NULL == root) {
            return 0;
        }
        int left_depth = maxDepth(root->left);
        int right_depth = maxDepth(root->right);
        return (left_depth > right_depth ? left_depth + 1 : right_depth + 1);
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);

    Solution a = Solution();
    cout << a.maxDepth(root) << endl;

    return 0;
}
