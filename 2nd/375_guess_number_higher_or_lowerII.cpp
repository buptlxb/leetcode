#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1));
        return getMoneyAmount(dp, 1, n);
    }
    int getMoneyAmount (vector<vector<int>> &dp, int a, int b) {
        if (a >= b) return 0;
        if (dp[a][b]) return dp[a][b];
        int t = numeric_limits<int>::max();
        for (int k = a; k <= b; ++k)
            t = min(t, k+max(getMoneyAmount(dp, a, k-1), getMoneyAmount(dp, k+1, b)));
        return dp[a][b] = t;
    }
};

int main(void)
{
    return 0;
}
