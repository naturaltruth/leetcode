/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: reverse_linked_list.cpp,v 0.0 2015-08-16 星期日 12:50:27  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   reverse_linked_list.cpp
 * @author zhoujin
 * @date   2015-08-16 星期日 12:50:27
 * @mail   zhoujin1224@gmail.com
 * @brief  Reverse a singly linked list.
 *
 * click to show more hints.
 *
 * Hint:
 * A linked list can be reversed either iteratively or recursively. Could you implement both?
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
    ListNode* reverseList(ListNode* head) {
        if (NULL == head || NULL == head->next) return head;
        ListNode* tmp = reverseList(head->next); //先反转后面的链表
        head->next->next = head;
        head->next = NULL;

        return tmp;
    }

    ListNode* reverseList2(ListNode* head) {
        if (NULL == head || NULL == head->next) return head;

        ListNode* prev = NULL;
        ListNode* curr = head;
        while (NULL != curr) {
            ListNode *tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        return prev;
    }
};


int main () {
    Solution sol = Solution();
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    
    ListNode* ret = sol.reverseList(head);
    while (ret != NULL) {
        cout << ret->val << " ";
        ret = ret->next;
    }
    cout << endl;

    return 0;
}
