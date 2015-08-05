/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: intersection_of_two_linked_lists.cpp,v 0.0 2015-07-30 星期四 09:51:05  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   intersection_of_two_linked_lists.cpp
 * @author zhoujin
 * @date   2015-07-30 星期四 09:51:05
 * @mail   zhoujin1224@gmail.com
 * @brief  Write a program to find the node at which the intersection of two singly linked lists begins.
 *
 *
 * For example, the following two linked lists:
 *
 * A:          a1 → a2
 *                    ↘
 *                      c1 → c2 → c3
 *                    ↗            
 * B:     b1 → b2 → b3
 * begin to intersect at node c1.
 *
 * Notes:
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function returns.
 * You may assume there are no cycles anywhere in the entire linked structure.
 * Your code should preferably run in O(n) time and use only O(1) memory.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (NULL == headA || NULL == headB) {
            return NULL;
        }
        int len_a = 0, len_b = 0;
        ListNode *tmp = headA;
        while (NULL != tmp) {
            ++len_a;
            tmp = tmp->next;
        }
        tmp = headB;
        while (NULL != tmp) {
            ++len_b;
            tmp = tmp->next;
        }
        ListNode *pa = headA, *pb = headB;
        if (len_a > len_b) {
            for (int i = 0; i < len_a - len_b; ++i) {
                pa = pa->next;
            }
        } else {
            for (int i = 0; i < len_b - len_a; ++i) {
                pb = pb->next;
            }
        }
        while (NULL != pa && NULL != pb) {
            if  (pa == pb) {
                return pa;
            }
            pa = pa->next;
            pb = pb->next;
        }
        
        return NULL;
    }
};

int main () {
    return 0;
}
