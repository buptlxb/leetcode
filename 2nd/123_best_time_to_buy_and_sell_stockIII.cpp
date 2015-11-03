#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        if (prices.size() < 2)
            return ret;
        vector<int> forward(prices.size(), 0);
        vector<int> backward(prices.size(), 0);
        int last = 0;
        for (vector<int>::size_type i = 1, iend = prices.size(); i < iend; ++i) {
            last += prices[i] - prices[i-1];
            forward[i] = max(forward[i-1], last);
            last = max(last, 0);
        }
        last = 0;
        for (vector<int>::size_type i = prices.size()-1; i > 0; --i) {
            last += prices[i] - prices[i-1];
            backward[i-1] = max(backward[i], last);
            ret = max(backward[i-1] + forward[i-1], ret);
            last = max(last, 0);
        }
        return max(ret, forward.back());
    }
};

int main(void)
{
    return 0;
}
