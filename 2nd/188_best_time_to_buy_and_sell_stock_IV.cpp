#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type sz_t;
    int maxProfit(int k, vector<int>& prices) {
        const sz_t size = prices.size();
        if (size < 2)
            return 0;
        if (k >= size)
            return maxProfit(prices);
        vector<int> local(k+1);
        vector<int> global(k+1);
        int prev = prices.front();
        for (auto x : prices) {
            int profit = x - prev;
            prev = x;
            for (int j = k; j > 0; --j) {
                local[j] = max(local[j] + profit, global[j-1] + max(profit, 0));
                global[j] = max(local[j], global[j]);
            }
        }
        return global[k];
    }
    int maxProfit(vector<int> &prices) {
        int ret = 0;
        int prev =  prices.front();
        for (auto x : prices) {
            ret += max(0, x - prev);
            prev = x;
        }
        return ret;
    }
};

int main(void)
{
    return 0;
}
