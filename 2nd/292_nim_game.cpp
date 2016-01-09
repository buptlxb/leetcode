#include <iostream>
#include <cassert>

using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        assert(n > 0);
        return n % 4 != 0;
    }
};

int main(void)
{
    return 0;
}
