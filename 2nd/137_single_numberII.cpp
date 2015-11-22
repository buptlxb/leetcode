#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0;
        int twos = 0;
        int threes = 0;
        for (auto x : nums) {
            twos |= ones & x;
            ones ^= x;
            threes = ones & twos;
            ones &= ~threes;
            twos &= ~threes;
        }
        return ones;
    }
};

int main(void)
{
    return 0;
}
