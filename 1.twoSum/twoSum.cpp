/*************************************************************************
	> File Name: twoSum.cpp
	> Author: zhoujin
	> Mail: zhoujin1224@gmail.com
	> Created Time: Sun 30 Nov 2014 10:06:27 AM CST
	> Brief: Given an array of integers, find two numbers such that
             they add up to a specific target number.
             The function twoSum should return indices of the two numbers 
             such that they add up to the target, where index1 must be 
             less than index2. Please note that your returned answers
             (both index1 and index2) are not zero-based.
             You may assume that each input would have exactly one solution. 
             Input: numbers={2, 7, 11, 15}, target=9
             Output: index1=1, index2=2 
************************************************************************/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        std::vector<int> index;
        for (int i = 0; i < numbers.size(); ++i) {
            if (mmap.end() == mmap.find(numbers[i])) {
                mmap[target - numbers[i]] = i;
            } else {
                index.push_back(mmap[numbers[i]] + 1);
                index.push_back(i + 1);
                break;
            }
        }

        return index;
    }

    std::map<int, int> mmap; 
};

int main() {
    Solution su;
    std::vector<int> num;
    num.push_back(2);
    num.push_back(7);
    num.push_back(11);
    num.push_back(15);
    int target = 9;
    std::vector<int> vec = su.twoSum(num, target);

    if (0 != vec.size()) {
        std::cout << "index1=" << vec[0] << ", index2=" << vec[1] << std::endl;
    }

    return 0;
}
