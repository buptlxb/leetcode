#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <climits>

using namespace std;

class Solution {
public:
    typedef vector<string>::size_type sz_t;
    int minCut(string s) {
        const sz_t len = s.size();
        if (len < 2) {
            return 0;
        }
        vector<vector<bool> > dp(len, vector<bool>(len, false));
        vector<int> ret(len+1, 0);
        for (sz_t i = s.size(); i > 0; --i) {
            ret[i-1] = len;
            for (sz_t j = i-1; j < len; ++j) {
                if (s[i-1] == s[j] && (j-i+1 < 2 || dp[i][j-1])) {
                    dp[i-1][j] = true;
                    ret[i-1] = min(ret[i-1], ret[j+1]+1);
                }
            }
        }
        return ret[0]-1;
    }
};

int main(void)
{
    Solution s;
    assert(0 == s.minCut("a") && "'a' minCut is 0");
    assert(1 == s.minCut("aab") && "'aab' minCut is 1");
    assert(75 == s.minCut("fifgbeajcacehiicccfecbfhhgfiiecdcjjffbghdidbhbdbfbfjccgbbdcjheccfbhafehieabbdfeigbiaggchaeghaijfbjhi"));
    cout << s.minCut("bb") << endl;
    return 0;
}
