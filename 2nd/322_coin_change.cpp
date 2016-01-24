#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type sz_t;
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, numeric_limits<int>::max()-1);
        dp[0] = 0;
        for (sz_t i = 0; i < amount; ++i) {
            for (sz_t j = 0, jend = coins.size(); j < jend; ++j) {
                if (i + coins[j] <= amount)
                    dp[i+coins[j]] = min(dp[i+coins[j]], dp[i]+1);
            }
        }
        return dp[amount] == numeric_limits<int>::max()-1 ? -1 : dp[amount];
    }
};

int main(void)
{
    Solution s;
    vector<int> coins{1, 2, 5};
    cout << s.coinChange(coins, 11) << endl;
    return 0;
}
