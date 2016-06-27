#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    unsigned abs(int x) { return x > 0 ? x : -x;}
    int divide(int dividend, int divisor) {
        if (divisor == 0)
            return INT_MAX;
        bool is_neg = (dividend ^ divisor)>>31;
        int res = 0;
        if (dividend == INT_MIN) {
            dividend += abs(divisor);
            if (divisor == -1)
                return INT_MAX;
            res++;
        }
        if (divisor == INT_MIN)
            return res;
        unsigned dvd = abs(dividend);
        unsigned dvs = abs(divisor);

        int digits = 0;
        while (dvd>>1 >= dvs) {
            ++digits;
            dvs <<= 1;
        }
        while (digits >= 0) {
            if (dvd >= dvs) {
                res += 1 << digits;
                dvd -= dvs;
            }
            dvs >>= 1;
            --digits;
        }
        return is_neg ? -res : res;
    }
};

int main(void)
{
    cout << Solution().divide(-2147483648, 2) << endl;
    return 0;
}
