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
        pass