/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: remove_nth_node_from_end_of_list.cpp,v 0.0 2015-07-16 星期四 07:05:34  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   remove_nth_node_from_end_of_list.cpp
 * @author zhoujin
 * @date   2015-07-16 星期四 07:05:34
 * @mail   zhoujin1224@gmail.com
 * @brief  Given a linked list, remove the nth node from the end of list and return its head.
 *
 * For example,
 *
 *    Given linked list: 1->2->3->4->5, and n = 2.
 *
 *       After removing the second node from the end, the linked list becomes 1->2->3->5.
 *       Note:
 *       Given n will always be valid.
 *       Try to do this in one pass.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (NULL == head) {
            return head;
        }
        ListNode *front = head;
        ListNode *behind = head;
        ListNode *prev = behind;
        for (int i = 0; i < n - 1; ++i) {
            front = front->next;
        }
        while (front->next != NULL) {
            front = front->next;
            prev = behind;
            behind = behind->next;
        }
        if (prev == behind) {
            //删除头结点
            ListNode *tmp = head;
            head = head->next;
            delete tmp;
        } else {
            prev->next = behind->next;
            delete behind;
        }

        return head;      
    }
};

int main () {
    Solution sol = Solution();
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    sol.removeNthFromEnd(head, 2);

    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

    return 0;
}
