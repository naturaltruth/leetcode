#!/usr/bin/env python
# encoding: utf-8

###############################
# Reverse digits of an integer.

# Example1: x = 123, return 321
# Example2: x = -123, return -321

# Have you thought about this?
# Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

# If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

# Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

# For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

# Update (2014-11-10):
#    Test cases had been added to test the overflow behavior.
###############################


class Solution:
    # @param {integer} x
    # @return {integer}
    def reverse(self, x):
        is_pos = 1
        if x < 0:
            is_pos = -1
            x = is_pos * x
        ret = 0
        while (x != 0):
            # Python中负数除法有些特殊,和 int_min对比时需要使用<=
            if is_pos * ret > self.int_max / 10 or is_pos * ret <= self.int_min / 10:
                return 0
            ret = ret * 10 + x % 10
            x = x / 10
        return ret * is_pos

    def __init__(self):
        self.int_max = 2147483647
        self.int_min = -self.int_max - 1

a = Solution()

print a.reverse(123)
print a.reverse(-123)
print a.reverse(-1000000003)
print a.reverse(-1563847412)
