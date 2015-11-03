#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        for (vector<int>::size_type i = 1, iend = prices.size(); i < iend; ++i) {
            if (prices[i] >= prices[i-1])
                ret += prices[i] - prices[i-1];
        }
        return ret;
    }
};

int main(void)
{
    return 0;
}
