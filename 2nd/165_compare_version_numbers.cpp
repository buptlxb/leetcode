#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        istringstream is1(version1), is2(version2);
        int a, b;
        char c;
        do {
            is1 >> a >> c;
            is2 >> b >> c;
            if (a > b)
                return 1;
            else if (a < b)
                return -1;
        } while (is1 && is2);
        b = 0;
        while (is1) {
            is1 >> a >> c;
            if (a > b)
                return 1;
        }
        a = 0;
        while (is2) {
            is2 >> b >> c;
            if (a < b)
                return -1;
        }
        return 0;
    }
};

int main(void)
{
    Solution s;
    assert(-1 == s.compareVersion("0.1", "1.1"));
    assert(-1 == s.compareVersion("1.1", "1.2"));
    assert(-1 == s.compareVersion("1.2", "13.37"));
    assert(0 == s.compareVersion("01", "1"));
    assert(0 == s.compareVersion("1.0", "1"));
    return 0;
}
