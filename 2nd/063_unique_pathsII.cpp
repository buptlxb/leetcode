#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type sz_t;
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        vector<vector<int> > dp(obstacleGrid);
        dp[0][0] = 1 - obstacleGrid[0][0];
        for (sz_t i = 1, iend = dp.size(); i < iend; ++i) {
            dp[i][0] = obstacleGrid[i][0] ? 0 : dp[i-1][0];
        }
        for (sz_t i = 1, iend = dp[0].size(); i < iend; ++i) {
            dp[0][i] = obstacleGrid[0][i] ? 0 : dp[0][i-1];
        }
        for (sz_t i = 1, iend = dp.size(); i < iend; ++i) {
            for (sz_t j = 1, jend = dp[i].size(); j < jend; ++j) {
                dp[i][j] = obstacleGrid[i][j] ? 0 : dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp.back().back();
    }
};

int main(void)
{
    return 0;
}
