#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0)
            return false;
        return 1162261467 % n == 0;
    }
};

int main(void)
{
    return 0;
}
