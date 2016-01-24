#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type sz_t;
    int maxCoins(vector<int>& nums) {
        if (nums.empty())
            return 0;
        vector<int> aux;
        aux.reserve(nums.size()+2);
        aux.push_back(1);
        aux.insert(aux.end(), nums.begin(), nums.end());
        aux.push_back(1);
        vector<vector<int>> dp(nums.size()+2, vector<int>(nums.size()+2));
        for (sz_t len = 1; len <= nums.size(); ++len) {
            for (sz_t left = 1, right = left+len-1; right <= nums.size(); ++left, right=left+len-1) {
                for (sz_t k = left; k <= right; ++k) {
                    dp[left][right] = max(dp[left][right], aux[left-1]*aux[k]*aux[right+1] + dp[left][k-1] + dp[k+1][right]);
                }
                cout << dp[left][right] << " ";
            }
            cout << endl;
        }
        return dp[1][nums.size()];
    }
};

int main(void)
{
    vector<int> nums{3, 1, 5, 8};
    Solution s;
    cout << s.maxCoins(nums) << endl;
    return 0;
}
