#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        const int base = 26;
        int ret = 0;
        for (auto c : s) {
            ret = ret * base + c - 'A' + 1;
        }
        return ret;
    }
};

int main(void)
{
    Solution s;
    assert(1 == s.titleToNumber("A"));
    assert(26 == s.titleToNumber("Z"));
    assert(27 == s.titleToNumber("AA"));
    return 0;
}
