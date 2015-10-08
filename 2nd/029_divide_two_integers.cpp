#include <iostream>
#include <cstdlib>
#include <climits>
#include <cstdint>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0)
            return INT_MAX;
        int ret = 0;
        bool isNeg = (dividend ^ divisor) >> 31;
        if (dividend == INT_MIN) {
            if (divisor == -1)
                return INT_MAX;
            if (divisor == INT_MIN)
                return 1;
            dividend += abs(divisor);
            ++ret;
        }
        uint32_t a = abs(dividend);
        uint32_t b = abs(divisor);
        int i = 0;
        while (a>>1 >= b) {
            ++i;
            b <<= 1;
        }
        while (i >= 0) {
            if (a >= b) {
                ret += 1 << i;
                a -= b;
            }
            b >>= 1;
            --i;
        }
        return isNeg ? -ret : ret;
    }
};

int main(void)
{
    cout << Solution().divide(-2147483648, 2) << endl;
    return 0;
}
