#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.size() < 2)
            return nums;
        vector<pair<int, int>> dp(nums.size(), pair<int, int>(1, -1));
        pair<int, int> lds(0, -1);
        sort(nums.begin(), nums.end());
        for (int i = 1, iend = nums.size(); i < iend; ++i) {
            for (int j = i-1; j >= 0; --j) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[i].first < dp[j].first+1) {
                        dp[i].first = dp[j].first+1;
                        dp[i].second = j;
                    }
                }
            }
            if (lds.first < dp[i].first) {
                lds.first = dp[i].first;
                lds.second = i;
            }
        }
        vector<int> ret;
        while (lds.second != -1) {
            ret.push_back(nums[lds.second]);
            lds.second = dp[lds.second].second;
        }
        return ret;
    }
};

int main(void)
{
    return 0;
}
