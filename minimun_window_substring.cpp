#include <iostream>
#include <string>
#include <climits>

using std::string;
using std::cout;
using std::endl;

class Solution {
public:
    string minWindow(string S, string T) {
        unsigned int expected[256] = {0, };
        for (string::iterator iter = T.begin(); iter != T.end(); iter++) {
            expected[*iter]++;
        }
        unsigned int found[256] = {0, };
        string::size_type found_total = 0;
        string::size_type win_start = 0;
        string::size_type win_size = INT_MAX;
        for (string::iterator iter = S.begin(), start = S.begin(); iter != S.end(); iter++) {
            if (expected[*iter]) {
                found[*iter]++;
                if (found[*iter] <= expected[*iter])
                    found_total++;
                if (found_total == T.size()) {
                    while (!expected[*start] || expected[*start] < found[*start]) {
                        found[*start]--;
                        start++;
                    }
                    string::size_type size = iter - start + 1;
                    if (size < win_size) {
                        win_start = start-S.begin();
                        win_size = size;
                    }
                    found[*start]--;
                    start++;
                    found_total--;
                }
            }
        }
        return win_size == INT_MAX ? "" : S.substr(win_start, win_size);
    }
};

int main(void)
{
    string s = "a";
    string t = "aa";
    cout << Solution().minWindow(s, t) << endl;
    return 0;
}
