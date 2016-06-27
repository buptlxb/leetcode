#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type s_t;
    int maxProfit(int k, vector<int>& prices) {
        s_t size = prices.size();
        if (k >= size)
            return maxProfit(prices);
        vector<int> local(k+1, 0);
        vector<int> global(k+1, 0);
        for (s_t i = 1; i < size; ++i) {
            int profit = prices[i] - prices[i-1];
            for (int j = k; j > 0; --j) {
                local[j] = max(local[j]+profit, global[j-1]+max(profit, 0));
                global[j] = max(local[j], global[j]);
            }
            copy(local.begin(), local.end(), ostream_iterator<int>(cout, ", "));
            cout << endl;
            copy(global.begin(), global.end(), ostream_iterator<int>(cout, ", "));
            cout << endl << "----------" << endl;
        }
        return global[k];
    }
    int maxProfit(vector<int>& prices) {
        int ret = 0;
        for (s_t i = prices.size()-1; i > 0; --i) {
            if (prices[i-1] < prices[i])
                ret += prices[i] - prices[i-1];
        }
        return ret;
    }
};

int main(void)
{
    int array[] = {1, 4, 3, 4, 2, 4};
    vector<int> vec(array, array+sizeof(array)/sizeof(array[0]));
    cout << Solution().maxProfit(3, vec) << endl;
    return 0;
}
