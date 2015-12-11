#include <iostream>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int bits = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            ++bits;
        }
        return m << bits;
    }
};

int main(void)
{
    return 0;
}
