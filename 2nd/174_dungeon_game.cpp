#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef vector<vector<int> >::size_type sz_t;
    int calculateMinimumHP(vector<vector<int> >& dungeon) {
        if (dungeon.empty())
            return 0;
        vector<vector<int> > dp(dungeon.size(), vector<int>(dungeon.front().size(), 1));
        dp.back().back() = max(1, 1-dungeon.back().back());
        for (sz_t i = dp.size()-1; i > 0; --i) {
            dp[i-1].back() = max(1, dp[i].back()-dungeon[i-1].back());
        }
        for (sz_t i = dp.back().size()-1; i > 0; --i) {
            dp.back()[i-1] = max(1, dp.back()[i]-dungeon.back()[i-1]);
        }
        for (sz_t i = dp.size()-1; i > 0; --i) {
            for (sz_t j = dp[i].size()-1; j > 0; --j) {
                dp[i-1][j-1] = min(max(1, dp[i][j-1]-dungeon[i-1][j-1]), max(1, dp[i-1][j]-dungeon[i-1][j-1]));
            }
        }
        return dp.front().front();
    }
};

int main(void)
{
    return 0;
}
