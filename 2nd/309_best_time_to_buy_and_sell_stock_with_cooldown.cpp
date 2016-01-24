#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type sz_t;
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        vector<int> sells(prices.size()), buys(prices.size());
        buys[0] = -prices[0];
        for (sz_t i = 1, iend = prices.size(); i < iend; ++i) {
            sells[i] = max(sells[i-1], buys[i-1]+prices[i]);
            if (i > 1)
                buys[i] = max(buys[i-1], sells[i-2]-prices[i]);
            else
                buys[i] = max(buys[i-1], -prices[i]);
        }
        return sells.back();
    }
};

int main(void)
{
    return 0;
}
