#include <iostream>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        int ret = 0, base = 1, low = 1;
        while (n > 0) {
            ret += (n + 8) / 10 * base + (n % 10 == 1) * low;
            low += n % 10 * base;
            n /= 10;
            base *= 10;
        }
        return ret;
    }
};

int main(void)
{
    cout << Solution().countDigitOne(13) << endl;
    return 0;
}
