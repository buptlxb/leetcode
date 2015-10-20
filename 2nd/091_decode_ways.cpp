#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type sz_t;
    int numDecodings(string s) {
        if (s.size() == 0 || s[0] == '0')
            return 0;
        int a, b, c;
        a = b = c = 1;
        for (sz_t i = 1, iend = s.size(); i < iend; ++i) {
            if (s[i] == '0') {
                if (s[i-1] == '1' || s[i-1] == '2')
                    c = a;
                else
                    return 0;
            } else {
                if (s[i-1] == '0' || s[i-1] > '2')
                    c = b;
                else if (s[i-1] == '2' && s[i] > '6')
                    c = b;
                else c = b + a;
            }
            a = b;
            b = c;
        }
        return b;
    }
};

int main(void)
{
    Solution s;
    assert(s.numDecodings("12") == 2);
    return 0;
}
