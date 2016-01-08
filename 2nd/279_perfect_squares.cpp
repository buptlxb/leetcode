#include <iostream>
#include <cassert>
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        assert(n > 0);
        vector<int> dp(n+1, numeric_limits<int>::max());
        dp[0] = 0;
        for (int i = 0; i <= n; ++i)
            for (int j = 1; i + j*j <= n; ++j)
                dp[i+j*j] = min(dp[i+j*j], dp[i]+1);
        return dp.back();
    }
};

int main(void)
{
    Solution s;
    //for (int i = 1; i <= 20; ++i)
    //    cout << i << ":" << s.numSquares(i) << endl;

    cout << 462 << ":" << s.numSquares(100000) << endl;
    return 0;
}
