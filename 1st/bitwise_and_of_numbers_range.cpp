#include <iostream>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int bits = 0;
        while (m && n) {
            if (m == n)
                return m << bits;
            m >>= 1;
            n >>= 1;
            ++bits;
        }
        return 0;
    }
};

int main(void)
{
    cout << Solution().rangeBitwiseAnd(5, 7) << endl;
    return 0;
}
