#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[i] += dp[j-1]*dp[i-j];
            }
        }
        return dp[n];
    }
};

int main(void)
{
    Solution s;
    assert(s.numTrees(1)==1);
    assert(s.numTrees(2)==2);
    assert(s.numTrees(3)==5);
    return 0;
}
