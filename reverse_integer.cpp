#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int ret = 0;
        if (x == -2147483648)
            return 0;
        int num = x > 0 ? x : -x;
        while (num >= 10) {
            int remainder = num % 10;
            num = num / 10;
            if (ret > (2147483647 - remainder * 10) / 10)
                return 0;
            ret = (ret  + remainder) * 10;
        }
        ret += num;
        ret = x > 0 ? ret : -ret;
        return ret;
    }
};

int main(void)
{
    int a = 10;
    cout << a << "->" << Solution().reverse(a) << endl;
    return 0;
}
