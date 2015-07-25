/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: same_tree.cpp,v 0.0 2015-07-25 星期六 08:26:12  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   same_tree.cpp
 * @author zhoujin
 * @date   2015-07-25 星期六 08:26:12
 * @mail   zhoujin1224@gmail.com
 * @brief  Given two binary trees, write a function to check if they are equal or not.
 *
 * Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
 *
 **/

#include <iostream>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (NULL == p && NULL == q) {
            return true;
        }
        if ((NULL == p && NULL != q) || (NULL != p && NULL == q)) {
            return false;
        }
        if (p->val != q->val) {
            return false;
        }
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

