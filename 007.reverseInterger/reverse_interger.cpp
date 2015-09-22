/**********************************
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

Update (2014-11-10):
   Test cases had been added to test the overflow behavior.
************************************/

#include <iostream>
#include <limits.h>
using std::cout;
using std::endl;

#define _INT_MAX_ 2147483647
#define _INT_MIN_ (-_INT_MAX_ - 1)

class Solution {
  public:
    int reverse(int x) {
        int ret = 0;
        while (x != 0) {
            if (ret > _INT_MAX_ / 10 || ret < _INT_MIN_ / 10) {
                return 0;
            }
            ret = ret * 10 + x % 10;
            x /= 10;
        }

        return ret;
    }
};

int main() {
    Solution a;
    int res = a.reverse(123);
    cout << res << endl;
    res = a.reverse(-123);
    cout << res << endl;
    res = a.reverse(-100);
    cout << res << endl;
    res = a.reverse(1000000003);
    cout << res << endl;

    return 0;
}
