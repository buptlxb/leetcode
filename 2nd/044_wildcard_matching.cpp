#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    typedef string::size_type sz_t;
    bool isMatch(string s, string p) {
        const sz_t len1 = s.size()+1;
        const sz_t len2 = p.size()+1;
        vector<vector<bool> > dp(len2, vector<bool> (len1, false));
        dp[0][0] = true;
        for (sz_t i = 1; i < len2; ++i) {
            if (dp[i-1][0] && p[i-1] == '*')
                dp[i][0] = true;
            for (sz_t j = 1; j < len1; ++j) {
                if (s[j-1] == '?' || s[j-1] == p[i-1])
                    dp[i][j] = dp[i-1][j-1];
                else if (p[i-1] == '*') {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
            }
        }
        return dp[len2-1][len1-1];
    }
};

int main(void)
{
    return 0;
}
