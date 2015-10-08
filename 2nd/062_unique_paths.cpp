#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m > n)
            return combination(m-1, n-1);
        else
            return combination(n-1, m-1);
    }
    int combination(int m, int n) {
        if (n == 0)
            return 1;
        double ret = 1.0;
        for (int i = 1; i <= n; ++i) {
            ret = ret * (m + i) / i;
        }
        return ret;
    }
    int uniquePathsDP(int m, int n) {
        vector<vector<int> > dp(m, vector<int>(n));
        for (int i = 0; i < m; ++i)
            dp[i][0] = 1;
        for (int i = 0; i < n; ++i)
            dp[0][i] = 1;
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};

int main(void)
{
    cout << Solution().uniquePaths(7, 3) << endl;
    cout << Solution().uniquePathsDP(3, 7) << endl;
    return 0;
}
