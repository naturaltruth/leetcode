/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: delete_node_in_a_linked_list.cpp,v 0.0 2015-08-20 星期四 08:47:02  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   delete_node_in_a_linked_list.cpp
 * @author zhoujin
 * @date   2015-08-20 星期四 08:47:02
 * @mail   zhoujin1224@gmail.com
 * @brief  Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
 *
 * Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
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
    void deleteNode(ListNode* node) {
        if (NULL == node) return;
        ListNode* tmp = node->next;
        node->val = tmp->val;
        node->next = tmp->next;
        delete tmp;
    }
};

int main() {
    return 0;
}
