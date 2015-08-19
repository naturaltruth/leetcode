/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: invert_binary_tree.cpp,v 0.0 2015-08-20 星期四 00:10:33  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   invert_binary_tree.cpp
 * @author zhoujin
 * @date   2015-08-20 星期四 00:10:33
 * @mail   zhoujin1224@gmail.com
 * @brief  Invert a binary tree.
 *
 *      4
 *    /   \
 *   2     7
 *  / \   / \
 * 1   3 6   9
 * to
 *      4
 *    /   \
 *   7     2
 *  / \   / \
 * 9   6 3   1
 *
 **/

#include <iostream>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) return root;
        if (NULL == root->left && NULL == root->right) return root;
        TreeNode* tmp = root->right;
        root->right = root->left;
        root->left = tmp;
        if (NULL != root->left) invertTree(root->left);
        if (NULL != root->right) invertTree(root->right);

        return root;
    }
};

int main() {
    Solution sol = Solution();

    return 0;
}
