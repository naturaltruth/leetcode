/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: plus_one.cpp,v 0.0 2015-07-23 星期四 08:38:53  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   plus_one.cpp
 * @author zhoujin
 * @date   2015-07-23 星期四 08:38:53
 * @mail   zhoujin1224@gmail.com
 * @brief  Given a non-negative number represented as an array of digits, plus one to the number.
 *
 * The digits are stored such that the most significant digit is at the head of the list.
 *
 **/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.empty()) {
            return digits;
        }
        int size = digits.size();
        int num = digits[size - 1] + 1;
        digits[size - 1] = num % 10;
        int carry = num / 10;
        for (int i = size - 2; i >= 0; --i) {
            if (carry == 0) {
                break;
            }
            num = digits[i] + carry;
            digits[i] = num % 10;
            carry = num / 10;
        }
        if (carry > 0) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

int main () {
    Solution sol = Solution();
    vector<int> digits;
    int a[] = {1, 9, 9, 9};
    digits.insert(digits.end(), a, a + sizeof(a) / sizeof(int));

    sol.plusOne(digits);

    for (int i = 0; i < digits.size(); ++i) {
        cout << digits[i];
    }
    cout << endl;
    
    return 0;
}
