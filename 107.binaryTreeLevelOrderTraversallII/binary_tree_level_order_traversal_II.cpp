/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: binary_tree_level_order_traversal_II.cpp,v 0.0 2015-07-26 星期日 10:29:00  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   binary_tree_level_order_traversal_II.cpp
 * @author zhoujin
 * @date   2015-07-26 星期日 10:29:00
 * @mail   zhoujin1224@gmail.com
 * @brief  Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
 *
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its bottom-up level order traversal as:
 *  [
 *    [15,7],
 *    [9,20],
 *    [3]
 *  ]
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
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        vector<vector<int> > vec_vec;
        if (NULL == root) {
            return vec_vec;
        }
        node_vec.push_back(root);
        int cur = 0;
        int last = 1;
        while (cur < node_vec.size()) {
            last = node_vec.size();
            vector<int> vec;
            while (cur < last) {
                TreeNode *cur_node = node_vec[cur];
                vec.push_back(cur_node->val);
                if (NULL != cur_node->left) {
                    node_vec.push_back(cur_node->left);
                }
                if (NULL != cur_node->right) {
                    node_vec.push_back(cur_node->right);
                }
                ++cur;
            }
            vec_vec.insert(vec_vec.begin(), vec);
        }
        
        return vec_vec;
    }

  private:
    vector<TreeNode*> node_vec;
};

int main () {
    Solution sol = Solution();
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int> > vec_vec;

    vec_vec = sol.levelOrderBottom(root); 
    for (int i = 0; i < vec_vec.size(); ++i) {
        vector<int> vec = vec_vec[i];
        for (int j = 0; j < vec.size(); ++j) {
            cout << vec[j] << " ";
        }
        cout << endl;
    }

    return 0;
}
