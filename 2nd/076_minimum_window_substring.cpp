#include <iostream>
#include <string>
#include <climits>
#include <cassert>

using namespace std;

class Solution {
public:
    typedef string::size_type sz_t;
    string minWindow(string s, string t) {
        sz_t expected[128] = {0, };
        sz_t found[128] = {0, };
        for (string::iterator i = t.begin(), iend = t.end(); i != iend; ++i) {
            ++expected[*i];
        }
        sz_t winStart = 0;
        sz_t winSize = INT_MAX;
        sz_t foundTotal = 0;
        for (sz_t i = 0, start = 0, iend = s.size(); i < iend; ++i) {
            if (expected[s[i]]) {
                ++found[s[i]];
                if (found[s[i]] <= expected[s[i]])
                    ++foundTotal;
                if (foundTotal == t.size()) {
                    while (!expected[s[start]] || expected[s[start]] < found[s[start]]) {
                        --found[s[start]];
                        ++start;
                    }
                    sz_t size = i-start+1;
                    if (size < winSize) {
                        winStart = start;
                        winSize = size;
                    }
                    --found[s[start]];
                    --foundTotal;
                    ++start;
                }
            }
        }
        return winSize == INT_MAX ? "" : s.substr(winStart, winSize);
    }
};

int main(void)
{
    Solution s;
    assert(s.minWindow("ADOBECODEBANC", "ABC") == "BANC");
    return 0;
}
