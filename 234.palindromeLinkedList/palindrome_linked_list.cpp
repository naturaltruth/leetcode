/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: palindrome_linked_list.cpp,v 0.0 2015-08-21 星期五 10:52:57  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   palindrome_linked_list.cpp
 * @author zhoujin
 * @date   2015-08-21 星期五 10:52:57
 * @mail   zhoujin1224@gmail.com
 * @brief  Given a singly linked list, determine if it is a palindrome.
 *
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
 *
 **/

#include <iostream>
#include <stack>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    bool isPalindrome(ListNode* head) {
        if (NULL == head || NULL == head->next) {
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast) {
            //奇数个结点
            slow = slow->next;
        }
        cout << slow->val << endl;
        slow = reverseList(slow);
        while (slow) {
            if (head->val != slow->val) return false;
            head = head->next;
            slow = slow->next;
        }

        return true;
    }

  private:
    ListNode* reverseList(ListNode* head) {
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
  public:
    bool isPalindrome2(ListNode* head) {
        if (NULL == head || NULL == head->next) {
            return true;
        }
        stack<int> s;
        ListNode* fast = head;
        ListNode* slow = head;
        /*
        bool is_even = false;
        while (fast->next) {
            s.push(slow->val);
            slow = slow->next;
            fast = fast->next;
            if (!fast->next) {
                //出现这种情形,表明是偶数个结点
                is_even = true;
                break;
            }
            fast = fast->next;
        }
        if (!is_even) {
            slow = slow->next;
        }
        */
        while (fast && fast->next) {
            s.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast) {
            //奇数个结点
            slow = slow->next;
        }
        while (slow) {
            if (slow->val != s.top()) {
                return false;
            }
            s.pop();
            slow = slow->next;
        }

        return true;
    }
};

int main () {
    Solution sol = Solution();
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    //head->next->next = new ListNode(3);
    //head->next->next->next = new ListNode(2);
    //head->next->next->next->next = new ListNode(1);
    cout << sol.isPalindrome(head) << endl;

    return 0;
}
