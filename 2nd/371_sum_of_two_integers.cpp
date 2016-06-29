#include <iostream>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        int ret = 0, carry = 0;
        for (int i = 0; i < 32; ++i) {
            int bita = (a & (1 << i)) != 0;
            int bitb = (b & (1 << i)) != 0;
            if (bita && bitb && carry) {
                ret |= 1 << i;
                carry = 1;
            } else if (!bita && !bitb && !carry) {
                carry = 0;
            } else if (bita ^ bitb ^ carry) {
                ret |= 1 << i;
                carry = 0;
            } else
                carry = 1;
        }
        return ret;
    }
};

int main(void)
{
    cout << Solution().getSum(-1, -2) << endl;
    return 0;
}
