/***************************************************************************
*
* Copyright (c) 2015 zhoujin All Rights Reserved
* $Id: count_primes.cpp,v 0.0 2015-08-10 星期一 16:30:00  zhoujin1 Exp $
*
***************************************************************************/

/**
 * @file   count_primes.cpp
 * @author zhoujin
 * @date   2015-08-10 星期一 16:30:00
 * @mail   zhoujin1224@gmail.com
 * @brief  Description:
 *
 * Count the number of prime numbers less than a non-negative number, n.
 *
 * Hint:
 * 1. Let's start with a isPrime function. To determine if a number is prime, we need to check if it is not divisible by any number less than n. The runtime complexity of isPrime function would be O(n) and hence counting the total prime numbers up to n would be O(n^2). Could we do better?
 * 2. As we know the number must not be divisible by any number > n / 2, we can immediately cut the total iterations half by dividing only up to n / 2. Could we still do better?
 *
 **/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int countPrimes(int n) {
        vector<int> is_prime(n, 1);
        for (int i = 2; i * i < n; ++i) {
            if (is_prime[i]) {
                for (int j = i * i; j < n; j += i) {
                    is_prime[j] = 0;
                }
            }
        }
        int count = 0;
        for (int i = 2; i < n; ++i) {
            count += is_prime[i];
        }
        return count;
    }
    // Time Limit Exceeded
    int countPrimes2(int n) {
        int count = 0;
        for (int i = 2; i <= n; ++i) {
            if (isPrime(i)) ++count;
        }
        return count;
    }
  private:
    bool isPrime(int n) {
        if (n < 2) return false;

        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) return false;
        }
        return true;
    }
};


int main () {
    Solution sol = Solution();
    cout << sol.countPrimes(1) << endl;
    cout << sol.countPrimes(100) << endl;

    return 0;
}
