/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: remove_linked_list_elements.cpp,v 0.0 2015-08-06 星期四 17:28:53  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   remove_linked_list_elements.cpp
 * @author zhoujin
 * @date   2015-08-06 星期四 17:28:53
 * @mail   zhoujin1224@gmail.com
 * @brief  Remove all elements from a linked list of integers that have value val.
 *
 * Example
 * Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
 * Return: 1 --> 2 --> 3 --> 4 --> 5
 *
 *
 *
 **/

#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode* removeElements(ListNode* head, int val) {
        if (NULL == head) return NULL;
        while (head->val == val) {
            head = head->next;
            if (NULL == head) return NULL;
        }
        ListNode *tmp = head;
        while (NULL != tmp->next) {
            if (tmp->next->val == val) {
                tmp->next = tmp->next->next;
            } else {
                tmp = tmp->next;
            }
        }
        return head;
    }
};


int main () {
    Solution sol = Solution();
    ListNode* head = new ListNode(1);
    //head->next = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(6);

    ListNode* p = sol.removeElements(head, 6);
    while (p != NULL) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;

    return 0;
}
