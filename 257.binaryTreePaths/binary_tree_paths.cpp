/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: binary_tree_paths.cpp,v 0.0 2015-08-18 星期二 21:14:17  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   binary_tree_paths.cpp
 * @author zhoujin
 * @date   2015-08-18 星期二 21:14:17
 * @mail   zhoujin1224@gmail.com
 * @brief  Given a binary tree, return all root-to-leaf paths.
 *
 * For example, given the following binary tree:
 *
 *    1
 *  /   \
 * 2     3
 *        \
 *         5
 * All root-to-leaf paths are:
 *
 * ["1->2->5", "1->3"]
 *
 **/

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> vec;
        if (NULL == root) {
            return vec;
        }
        path(root, "", vec);

        return vec;
    }
  private:
    void path(TreeNode* root, string str, vector<string> &vec) {
        char tmp[32];
        tmp[31] = '\0';
        if (NULL == root->left && NULL == root->right) {
            snprintf(tmp, sizeof(tmp), "%d", root->val);
            str += string(tmp);
            vec.push_back(str);
        }
        snprintf(tmp, sizeof(tmp), "%d", root->val);
        str += string(tmp);
        if (NULL != root->left) {
            path(root->left, str + "->", vec);
        }
        if (NULL != root->right) {
            path(root->right, str + "->", vec);
        }
    }
};

int main() {
    Solution sol = Solution();
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(5);
    
    vector<string> vec;
    vec = sol.binaryTreePaths(root);

    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << endl;
    }

    return 0;
}
