#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    typedef string::size_type s_t;
    int numDistinct(string s, string t) {
        vector<int> tmp(s.size()+1, 0);
        vector<vector<int> > dp(t.size()+1, tmp);
        for (s_t i = 0, iend = s.size(); i <= iend; ++i) {
            dp[0][i] = 1;
        }
        for (s_t i = 0, iend = t.size(); i < iend; ++i) {
            for (s_t j = 0, jend = s.size(); j < jend; ++j) {
                dp[i+1][j+1] = dp[i+1][j] + (t[i] == s[j] ? dp[i][j] : 0);
            }
        }
        return dp[t.size()][s.size()];
    }
    int numDistinct(string &s, string &t, s_t s_start, s_t t_start) {
        if (t.size() == t_start)
            return 1;
        if (s.size() == s_start)
            return 0;
        int ret = 0;
        for (s_t i = s_start, iend = s.size(); i < iend; ++i) {
            if (s[i] == t[t_start]) {
                ret += numDistinct(s, t, i+1, t_start+1);
            }
        }
        return ret;
    }
};

int main(void)
{
    cout << Solution().numDistinct("rabbbit", "rabbit") << endl;
    return 0;
}
