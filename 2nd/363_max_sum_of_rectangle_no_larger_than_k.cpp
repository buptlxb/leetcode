#include <iostream>
#include <vector>
#include <set>
#include <limits>

using namespace std;

class Solution {
public:
    typedef vector<vector<int>>::size_type sz_t;
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty())
            return 0;
        sz_t n = min(matrix.size(), matrix[0].size());
        sz_t m = max(matrix.size(), matrix[0].size());
        bool transpose = matrix.size() > matrix[0].size();
        int ret = numeric_limits<int>::min();
        for (sz_t i = 0; i < n; ++i) {
            vector<int> col_sum(m);
            for (sz_t x = i+1; x > 0; --x) {
                int cnt = 0;
                set<int> prefix_sum;
                prefix_sum.insert(0);
                for (sz_t y = 0; y < m; ++y) {
                    col_sum[y] += transpose ? matrix[y][x-1] : matrix[x-1][y];
                    cnt += col_sum[y];
                    auto minmax = prefix_sum.lower_bound(cnt-k);
                    if (minmax != prefix_sum.end()) {
                        ret = max(ret, cnt - *minmax);
                    }
                    prefix_sum.insert(cnt);
                }
            }
        }
        return ret;
    }
};

int main(void)
{
    Solution s;
    vector<vector<int>> matrix{{-1, 0, 1}, {0, -2, 3}};
    cout << s.maxSumSubmatrix(matrix, 2) << endl;
    return 0;
}
