#include <iostream>

using namespace std;

#define CHAR_BIT 8

typedef unsigned int uint32_t;

class Solution {
    public:
        uint32_t reverseBits(uint32_t n) {
            
            //unsigned char b = x;
            //b = ((b * 0x0802LU & 0x22110LU) | (b * 0x8020LU & 0x88440LU)) * 0x10101LU >> 16; 
            uint32_t r = n; // r will be reversed bits of v; first get LSB of v
            int s = sizeof(n) * CHAR_BIT - 1; // extra shift needed at end

            for (n >>= 1; n; n >>= 1) {   
                r <<= 1;
                r |= n & 1;
                s--;
            }
            r <<= s; // shift when v's highest bits are zero
            return r;
        }
};

int main(void)
{
    cout << 43261596 << " -> " << Solution().reverseBits(43261596) << endl;
    return 0;
}
