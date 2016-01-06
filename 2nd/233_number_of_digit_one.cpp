#include <iostream>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        int part = 1, ret = 0, base = 1;
        if (n < 1)
            return 0;
        while (n) {
            ret += (n + 8) / 10 * base + (n % 10 == 1) * part;
            part += n % 10 * base;
            n /= 10;
            base *= 10;
        }
        return ret;
    }
};

int main(void)
{
    return 0;
}
