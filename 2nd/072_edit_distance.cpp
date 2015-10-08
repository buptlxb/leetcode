#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type sz_t;
    int minDistance(string word1, string word2) {
        const sz_t len1 = word1.size();
        const sz_t len2 = word2.size();
        vector<vector<sz_t> > dp(len1+1, vector<sz_t>(len2+1));
        for (sz_t i = 0; i <= len1; ++i) {
            dp[i][0] = i;
        }
        for (sz_t j = 0; j <= len2; ++j) {
            dp[0][j] = j;
        }
        for (sz_t i = 1; i <= len1; ++i) {
            for (sz_t j = 1; j <= len2; ++j) {
                dp[i][j] = min(dp[i-1][j-1] + (word1[i-1] != word2[j-1]), min(dp[i-1][j]+1, dp[i][j-1]+1));
            }
        }
        return dp[len1][len2];
    }
};

int main(void)
{
    Solution s;
    assert(s.minDistance("abc", "aabc") == 1);
    assert(s.minDistance("a", "b") == 1);
    return 0;
}
