#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 1)
            return false;
        int cnt = 0;
        while (n) {
            ++cnt;
            n &= n-1;
        }
        return cnt < 2;
    }
};

int main(void)
{
    return 0;
}
