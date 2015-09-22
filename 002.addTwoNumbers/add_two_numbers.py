#!/usr/bin/env python
# coding=utf-8

############################################
# > File Name: add_two_numbers.py
# > Author: zhoujin
# > Mail: zhoujin1224@gmail.com
# > Created Time: Tue 09 Dec 2014 12:32:31 AM CST
# > Brief: You are given two linked lists representing
#            two non-negative numbers. The digits are stored
#            in reverse order and each of their nodes contain
#            a single digit. Add the two numbers and return it
#            as a linked list.
#            Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
#            Output: 7 -> 0 -> 8
############################################

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @return a ListNode
    def addTwoNumbers(self, l1, l2):
        head, tmp, val = None, None, 0
        while l1 != None and l2 != None:
            val = val + l1.val + l2.val
            node = ListNode(val % 10)
            val = val / 10
            if head == None:
                head = node
                tmp = head
            else:
                tmp.next = node
                tmp = tmp.next
            l1 = l1.next
            l2 = l2.next
        while l1 != None:
            val = val + l1.val
            node = ListNode(val % 10)
            val = val / 10
            tmp.next = node
            tmp = tmp.next
            l1 = l1.next
        while l2 != None:
            val = val + l2.val
            node = ListNode(val % 10)
            val = val / 10
            tmp.next = node
            tmp = tmp.next
            l2 = l2.next
        if val != 0:
            node = ListNode(val % 10)
            tmp.next = node

        return head

su = Solution()
l1 = ListNode(2)
l1.next = ListNode(4)
l1.next.next = ListNode(3)

l2 = ListNode(5)
l2.next = ListNode(6)
l2.next.next = ListNode(4)

ret = su.addTwoNumbers(l1, l2)

print "%d -> %d -> %d" % (ret.val, ret.next.val, ret.next.next.val)

l3 = ListNode(1)
l3.next = ListNode(8)

l4 = ListNode(0)

ret = su.addTwoNumbers(l3, l4)

print "%d -> %d" % (ret.val, ret.next.val)

l5 = ListNode(0)

l6 = ListNode(7)
l6.next = ListNode(3)

ret = su.addTwoNumbers(l5, l6)

print "%d -> %d" % (ret.val, ret.next.val)
