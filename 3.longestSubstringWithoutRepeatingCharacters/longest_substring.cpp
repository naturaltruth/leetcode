/*************************************************************************
	> File Name: longest_substring.cpp
	> Author: zhoujin
	> Mail: zhoujin1224@gmail.com
	> Created Time: Wed 03 Dec 2014 09:00:45 AM CST
	> Brief: Given a string, find the length of the longest substring
             without repeating characters.
             For example, the longest substring without repeating
             letters for "abcabcbb" is "abc", which the length is 3.
             For "bbbbb" the longest substring is "b", with the length of 1.
 ************************************************************************/
#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> pos;
        int max_len = 0;
        int prev_pos = -1;
        for (int i = 0; i < s.size(); ++i) {
            if (pos.end() != pos.find(s[i]) && pos[s[i]] > prev_pos) {
                prev_pos = pos[s[i]];
            }
            if (i - prev_pos > max_len) {
                max_len = i - prev_pos;
            }
            pos[s[i]] = i;
        }

        return max_len;
    }
};

int main() {
    Solution su;
    std::string s = "abcabcab";
    int max_len = su.lengthOfLongestSubstring(s);
    cout << max_len << endl;

    s = "bbbb";
    max_len = su.lengthOfLongestSubstring(s);
    cout << max_len << endl;

    s = "abcdefg";
    max_len = su.lengthOfLongestSubstring(s);
    cout << max_len << endl;

    return 0;
}
