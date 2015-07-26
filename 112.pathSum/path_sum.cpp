/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: path_sum.cpp,v 0.0 2015-07-27 星期一 00:23:50  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   path_sum.cpp
 * @author zhoujin
 * @date   2015-07-27 星期一 00:23:50
 * @mail   zhoujin1224@gmail.com
 * @brief  Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
 *
 * For example:
 * Given the below binary tree and sum = 22,
 *               5
 *              / \
 *             4   8
 *            /   / \
 *           11  13  4
 *          /  \      \
 *         7    2      1
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
    bool hasPathSum(TreeNode* root, int sum) {
        if (NULL == root) return false;
        if (NULL == root->left && NULL == root->right && root->val == sum) {
            return true;
        }
        return (hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val));
    }
};

int main () {
    Solution sol = Solution();
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->right->right = new TreeNode(1);
    cout << sol.hasPathSum(root, 126) << endl;

    return 0;
}
