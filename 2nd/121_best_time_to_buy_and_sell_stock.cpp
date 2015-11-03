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
        int last = 0;
        for (vector<int>::size_type i = 1, iend = prices.size(); i < iend; ++i) {
            last += prices[i] - prices[i-1];
            ret = max(ret, last);
            last = max(last, 0);
        }
        return ret;
    }
};

int main(void)
{
    return 0;
}
