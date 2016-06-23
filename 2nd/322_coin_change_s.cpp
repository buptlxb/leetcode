#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef vector<int>::reverse_iterator RIter;
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        int res = numeric_limits<int>::max();
        coinChange(coins.rbegin(), coins.rend(), amount, 0, res);
        return res == numeric_limits<int>::max() ? -1 : res;
    }
    void coinChange(RIter first, RIter last, int amount, int cur, int &res) {
        int val = *first++;
        for (int n = amount / val; n >= 0; --n) {
            int remain = amount - n*val;
            if (remain > 0 && first != last && (cur + n + (remain + *first - 1) / *first) < res)
                coinChange(first, last, remain, cur+n, res);
            else if (remain == 0 && cur + n < res)
                res = cur + n;
            else
                break;
        }
    }
};

int main(void)
{
    Solution s;
    vector<int> coins{1, 2, 5};
    cout << s.coinChange(coins, 11) << endl;
    return 0;
}
