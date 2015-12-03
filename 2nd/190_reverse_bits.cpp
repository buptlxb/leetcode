#include <iostream>
#include <cstdint>
#include <cassert>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = (n & 0xffff0000) >> 0x10 | (n & 0x0000ffff) << 0x10;
        n = (n & 0xff00ff00) >> 0x08 | (n & 0x00ff00ff) << 0x08;
        n = (n & 0xf0f0f0f0) >> 0x04 | (n & 0x0f0f0f0f) << 0x04;
        n = (n & 0xcccccccc) >> 0x02 | (n & 0x33333333) << 0x02;
        n = (n & 0xaaaaaaaa) >> 0x01 | (n & 0x55555555) << 0x01;
        return n;
    }
};

int main(void)
{
    Solution s;
    assert(964176192 == s.reverseBits(43261596));
    return 0;
}
