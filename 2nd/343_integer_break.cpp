#include <iostream>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        int ret = 1;
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;
        while (n > 4) {
            ret *= 3;
            n-= 3;
        }
        return ret * n;
    }
};

int main(void)
{
    return 0;
}
