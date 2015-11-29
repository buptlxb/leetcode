#include <iostream>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int ret = 0;
        while (n) {
            n /= 5;
            ret += n;
        }
        return ret;
    }
};

int main(void)
{
    return 0;
}
