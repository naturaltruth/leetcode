/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: swap_nodes_in_pairs.cpp,v 0.0 2015-09-25 星期五 17:03:33  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   swap_nodes_in_pairs.cpp
 * @author zhoujin
 * @date   2015-09-25 星期五 17:03:33
 * @mail   zhoujin1224@gmail.com
 * @brief  Given a linked list, swap every two adjacent nodes and return its head.
 *
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 *
 * Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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
    ListNode* swapPairs(ListNode* head) {
        if (NULL == head || NULL == head->next) {
            return head;
        }

        ListNode* cur = head;
        ListNode* prev = NULL;
        while (NULL != cur && NULL != cur->next) {
            ListNode* tmp = cur->next;
            if (cur == head) {
                head = tmp;
            }
            if (NULL != prev) {
                prev->next = tmp;
            }
            cur->next = tmp->next;
            tmp->next = cur;
            prev = cur;
            cur = cur->next;
        }

        return head;
    }
};

int main() {
    Solution sol = Solution();
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    //head->next->next->next = new ListNode(4);
    ListNode *ret = sol.swapPairs(head);

    while (ret != NULL) {
        cout << ret->val << " ";
        ret = ret->next;
    }
    cout << endl;

    return 0;
}
