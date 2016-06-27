#include <iostream>

using namespace std;


class Solution {
    public:
        int hammingWeight(int x) {
            int ret = 0;
            while (x) {
                ret++;
                x = x & (x-1);
            }
            return ret;
        }
};

int main(void)
{
    int  x = 3;
    cout << x << "'s hamming weight is " << Solution().hammingWeight(x) << endl;
    return 0;
}
