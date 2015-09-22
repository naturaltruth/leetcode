#!/usr/bin/env python
# coding=utf-8

############################################
# > File Name: twoSum.py
# > Author: zhoujin
# > Mail: zhoujin1224@gmail.com
# > Created Time: Sun 30 Nov 2014 10:41:05 AM CST
# > Brief: Given an array of integers, find two numbers such that
#            they add up to a specific target number.  The function
#            twoSum should return indices of the two numbers such
#            that they add up to the target, where index1 must be
#            less than index2. Please note that your returned answers
#            (both index1 and index2) are not zero-based.
#            You may assume that each input would have exactly one solution.
#            Input: numbers={2, 7, 11, 15}, target=9
#            Output: index1=1, index2=2
############################################


class Solution:
    # @return a tuple, (index1, index2)
    def twoSum(self, num, target):
        mmap = {}
        for i in range(0, len(num)):
            if not mmap.has_key(num[i]):
                mmap[target - num[i]] = i
            else:
                index1 = mmap[num[i]] + 1
                index2 = i + 1
                return tuple([index1, index2])
        return


su = Solution()
num = [2, 7, 11, 15]
target = 9
ret = su.twoSum(num, target)
if ret:
    print "index1=%d, index2=%d" % (ret[0], ret[1])
