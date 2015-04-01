#include <iostream>

using namespace std;

class Solution {
    public:
        int trailingZeroes(int n) {
            int ret = 0;
            while (n > 0) {
                int tmp = n / 5;
                ret += tmp;
                n = tmp;
            }
            return ret;
        }
};

int main(void)
{
    int x = 10;
    cout << x << "1's trailing zeroes are " << Solution().trailingZeroes(x) << endl;
    return 0;
}
