/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: merge_two_sorted_list.cpp,v 0.0 2015-07-16 星期四 07:45:20  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   merge_two_sorted_list.cpp
 * @author zhoujin
 * @date   2015-07-16 星期四 07:45:20
 * @mail   zhoujin1224@gmail.com
 * @brief  Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (NULL == l1) {
            return l2;
        }
        if (NULL == l2) {
            return l1;
        }
        ListNode* head = NULL, *l3 = NULL;
        if (l1->val < l2->val) {
            head = l3 = l1;
            l1 = l1->next;
        } else {
            head = l3 = l2;
            l2 = l2->next;
        }
        while (NULL != l1 && NULL != l2) {
            if (l1->val < l2->val) {
                l3->next = l1;
                l1 = l1->next;
                l3 = l3->next;
            } else {
                l3->next = l2;
                l2 = l2->next;
                l3 = l3->next;
            }
        }
        while (NULL != l1) {
            l3->next = l1;
            l1 = l1->next;
            l3 = l3->next;
        }
        while (NULL != l2) {
            l3->next = l2;
            l2 = l2->next;
            l3 = l3->next;
        }

        return head;        
    }
};

int main () {
    Solution sol = Solution();
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(4);
    ListNode *l2 = new ListNode(2);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(5);

    ListNode *l3 = sol.mergeTwoLists(l1, l2);

    while (l3 != NULL) {
        cout << l3->val << " ";
        l3 = l3->next;
    }
    cout << endl;

    return 0;
}
