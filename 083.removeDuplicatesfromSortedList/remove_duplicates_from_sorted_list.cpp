/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: remove_duplicates_from_sorted_list.cpp,v 0.0 2015-07-25 星期六 06:58:35  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   remove_duplicates_from_sorted_list.cpp
 * @author zhoujin
 * @date   2015-07-25 星期六 06:58:35
 * @mail   zhoujin1224@gmail.com
 * @brief  Given a sorted linked list, delete all duplicates such that each element appear only once.
 *
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
 *
 **/

#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (NULL == head || NULL == head->next) {
            return head;
        }
        ListNode *prev_node = head;
        int prev_val = head->val;
        ListNode *curr_node = prev_node->next;
        int curr_val = curr_node->val;
        while (NULL != curr_node) {
            if (curr_val == prev_val) {
                prev_node->next = curr_node->next;
                delete curr_node;
                curr_node = prev_node->next;
                if (NULL == curr_node) break;
                curr_val = curr_node->val;
            } else {
                prev_node = prev_node->next;
                prev_val = prev_node->val;
                curr_node = curr_node->next;
                if (NULL == curr_node) break;
                curr_val = curr_node->val;
            }
        }

        return head;
    }
};

int main () {
    Solution sol = Solution();
    ListNode *head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);
    ListNode *ret = sol.deleteDuplicates(head);
    
    while (ret != NULL) {
        cout << ret->val << " ";
        ret = ret->next;
    }
    cout << endl;

    return 0;
}
