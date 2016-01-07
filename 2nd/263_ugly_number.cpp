#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0)
            return false;
        while (num != 1) {
            if (num % 2 == 0)
                num /= 2;
            else if (num % 3 == 0)
                num /= 3;
            else if (num % 5 == 0)
                num /= 5;
            else
                break;
        }
        return num == 1;
    }
};

int main(void)
{
    Solution s;
    assert(s.isUgly(6));
    assert(s.isUgly(8));
    assert(!s.isUgly(14));
    return 0;
}
