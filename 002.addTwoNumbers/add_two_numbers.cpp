/*************************************************************************
	> File Name: add_two_numbers.cpp
	> Author: zhoujin
	> Mail: zhoujin1224@gmail.com
	> Created Time: Tue 09 Dec 2014 01:52:18 AM CST
	> Brief:
 ************************************************************************/
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (NULL == l1 && NULL == l2) {
            return NULL;
        }
        ListNode *head = NULL;
        ListNode *tmp = NULL;
        int val = 0;
        while (NULL != l1 && NULL != l2) {
            val = val + l1->val + l2->val;
            ListNode *node = new ListNode(val % 10);
            val = val / 10;
            if (NULL == head) {
                head = node;
                tmp = head;
            } else {
                tmp->next = node;
                tmp = tmp->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while (NULL != l1) {
            val = val + l1->val;
            ListNode *node = new ListNode(val % 10);
            val = val / 10;
            tmp->next = node;
            tmp = tmp->next;
            l1 = l1->next;
        }
        while (NULL != l2) {
            val = val + l2->val;
            ListNode *node = new ListNode(val % 10);
            val = val / 10;
            tmp->next = node;
            tmp = tmp->next;
            l2 = l2->next;
        }
        if (0 != val) {
            ListNode *node = new ListNode(val % 10);
            tmp->next = node;
        }

        return head;
    }
};

int main() {
    Solution su;

    ListNode *l1 = new ListNode(0);
    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(8);
    ListNode *ret = su.addTwoNumbers(l1, l2);
    cout << ret->val << " -> " << ret->next->val << endl;

    ListNode *l3 = new ListNode(7);
    l3->next = new ListNode(3);
    ListNode *l4 = new ListNode(0);
    ret = su.addTwoNumbers(l3, l4);
    cout << ret->val << " -> " << ret->next->val << endl;

    return 0;
}
