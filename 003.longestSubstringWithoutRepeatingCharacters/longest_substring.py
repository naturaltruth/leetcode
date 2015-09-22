#!/usr/bin/env python
# coding=utf-8

############################################
#	> File Name: longest_substring.py
#	> Author: zhoujin
#	> Mail: zhoujin1224@gmail.com
#	> Created Time: Wed 03 Dec 2014 08:36:10 AM CST
#	> Brief: Given a string, find the length of the longest substring
#            without repeating characters. For example, the longest
#            substring without repeating letters for "abcabcbb" is "abc",
#            which the length is 3. For "bbbbb" the longest substring is "b
#            with the length of 1.
############################################

class Solution:
    # @return an integer
    def lengthOfLongestSubstring(self, s):
        pos = {}
        prev_pos = -1
        max_len = 0
        for i in range(0, len(s)):
            if pos.has_key(s[i]):
                if pos[s[i]] > prev_pos:
                    prev_pos = pos[s[i]]
            dist = i - prev_pos
            if dist > max_len:
                max_len = dist
            pos[s[i]] = i
        return max_len


su = Solution()

l = 'abcabcab'
max_len = su.lengthOfLongestSubstring(l)
print max_len

l = 'bbbb'
max_len = su.lengthOfLongestSubstring(l)
print max_len

l = 'abcdefg'
max_len = su.lengthOfLongestSubstring(l)
print max_len
