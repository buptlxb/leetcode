#include <iostream>
#include <sstream>
#include <string>
#include <cassert>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        ostringstream os;
        while (n % 26) {
            os << itoa(n % 26);
            n /= 26;
        }
        if (n) {
            os << 'Z';
            n /= 26;
            if (n > 1)
                os << itoa(n-1);
        }
        string tmp = os.str();
        return string(tmp.rbegin(), tmp.rend());
    }
    char itoa(int x) {
        return 'A' - 1 + x;
    }
};

int main(void)
{
    Solution s;
    assert("A" == s.convertToTitle(1));
    assert("Z" == s.convertToTitle(26));
    assert("AA" == s.convertToTitle(27));
    assert("AZ" == s.convertToTitle(52));
    assert("BA" == s.convertToTitle(53));
    return 0;
}
