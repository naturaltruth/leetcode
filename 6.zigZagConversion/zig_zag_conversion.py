#!/usr/bin/env python
# encoding: utf-8

###############################
# The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows
# like this: (you may want to display this pattern in a fixed font for better legibility)
# P   A   H   N
# A P L S I I G
# Y   I   R
# And then read line by line: "PAHNAPLSIIGYIR"
# Write the code that will take a string and make this conversion given a number of rows:
# string convert(string text, int nRows);
# convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

# nRows = 3
# o       o       o
# ↓     ↗ ↓     ↗ ↓
# o   o   o   o   o
# ↓ ↗     ↓ ↗     ↓
# o       o       o

# nRows = 4
# o           o           o
# ↓         ↗ ↓         ↗ ↓
# o       o   o       o   o
# ↓     ↗     ↓     ↗     ↓
# o   o       o   o       o
# ↓ ↗         ↓ ↗         ↓
# o           o           o
###############################


class Solution:
    # @param {string} s
    # @param {integer} numRows
    # @return {string}
    def convert(self, s, numRows):
        s_len = len(s)
        if s_len == 0 or numRows <= 1:
            return s
        
        ret = []
        row = 0
        while (row < numRows and row < s_len):
            idx = row
            ret.append(s[idx])
            col = 1
            while idx < s_len:
                if row == 0 or row == numRows - 1:
                    idx += 2 * numRows - 2
                else:
                    if col % 2 == 1:
                        idx += 2 * (numRows - row - 1)
                    else:
                        idx += 2 * row
                if idx < s_len:
                    ret.append(s[idx])
                col += 1
            row += 1

        return ''.join(ret)

    def convert2(self, s, numRows):
        s_len = len(s)
        if s_len == 0 or numRows <= 1:
            return s
        
        ret = ''
        row = 0
        while (row < numRows and row < s_len):
            idx = row
            ret += s[idx]
            col = 1
            while idx < s_len:
                if row == 0 or row == numRows - 1:
                    idx += 2 * numRows - 2
                else:
                    if col % 2 == 1:
                        idx += 2 * (numRows - row - 1)
                    else:
                        idx += 2 * row
                if idx < s_len:
                    ret += s[idx]
                col += 1
            row += 1

        return ret

sol = Solution()
print sol.convert("PAYPALISHIRING", 3)
