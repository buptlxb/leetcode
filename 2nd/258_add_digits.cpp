#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        assert(num >= 0);
        if (num < 10)
            return num;
        return num % 9 ? num % 9 : 9;
    }
};

int main(void)
{
    return 0;
}
