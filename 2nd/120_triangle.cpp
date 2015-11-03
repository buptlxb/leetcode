#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type sz_t;
    int minimumTotal(vector<vector<int> >& triangle) {
        if (triangle.empty())
            return 0;
        vector<vector<int> > dp(2, vector<int>(triangle.size(), INT_MAX));
        int index = 0;
        dp[index][0] = triangle[0][0];
        for (sz_t i = 1; i < triangle.size(); ++i) {
            dp[1-index][0] = dp[index][0] + triangle[i][0];
            for (sz_t j = 1; j < triangle[i].size(); ++j) {
                dp[1-index][j] = triangle[i][j] + min(dp[index][j-1], dp[index][j]);
            }
            index = 1-index;
        }
        return *min_element(dp[index].begin(), dp[index].end());
    }
};

int main(void)
{
    return 0;
}
