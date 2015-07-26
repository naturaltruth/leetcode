/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: minumum_depth_of_binary_tree.cpp,v 0.0 2015-07-26 星期日 10:00:00  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   minumum_depth_of_binary_tree.cpp
 * @author zhoujin
 * @date   2015-07-26 星期日 10:00:00
 * @mail   zhoujin1224@gmail.com
 * @brief  Given a binary tree, find its minimum depth.
 *
 * The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 *
 **/

#include <iostream>
#include <limits.h>

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
    int minDepth(TreeNode* root) {
        if (NULL == root) {
            return 0;
        }
        //叶子节点
        if (NULL == root->left && NULL == root->right) {
            return 1;
        }
        int left_depth = INT_MAX;
        if (NULL != root->left) {
            left_depth = minDepth(root->left) + 1;
        }
        int right_depth = INT_MAX;
        if (NULL != root->right) {
            right_depth = minDepth(root->right) + 1;
        }
        return (left_depth > right_depth ? right_depth : left_depth);
    }
};
