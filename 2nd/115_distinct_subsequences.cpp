#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    typedef string::size_type sz_t;
    int numDistinct(string s, string t) {
        vector<vector<int> > dp(t.size()+1, vector<int> (s.size()+1, 0));
        for (sz_t i = 0, iend = dp.front().size(); i < iend; ++i)
            dp[0][i] = 1;
        for (sz_t i = 0, iend = dp.size(); i < iend; ++i)
            for (sz_t j = 0, jend = dp[i].size(); j < jend; ++j)
                dp[i+1][j+1] = dp[i+1][j] + (s[j] == t[i] ? dp[i][j] : 0);
        return dp[t.size()][s.size()];
    }
};

int main(void)
{
    return 0;
}
