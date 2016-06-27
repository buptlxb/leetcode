#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    typedef vector<int>::size_type s_t;
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        vector<int> dp(prices.size(), 0);
        s_t min = 0;
        for (s_t i = 1, iend = prices.size(); i < iend; ++i) {
            int tmp = prices[i] - prices[min];
            min = prices[min] < prices[i] ? min : i;
            dp[i] = dp[i-1] < tmp ? tmp : dp[i-1];
        }
        return dp[prices.size()-1];
    }
};

int main(void)
{
    int array[] = {1, 2, 3, 4};
    vector<int> vec(array, array+sizeof(array)/sizeof(array[0]));
    cout << Solution().maxProfit(vec) << endl;

}
