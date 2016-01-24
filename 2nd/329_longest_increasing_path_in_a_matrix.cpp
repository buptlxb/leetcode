#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type sz_t;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix.front().empty())
            return 0;
        vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix.front().size()));
        vector<vector<int>> mem(matrix.size(), vector<int>(matrix.front().size()));
        int ret = 0;
        for (sz_t i = 1; i <= matrix.size(); ++i) {
            for (sz_t j = 1;  j <= matrix[i-1].size(); ++j) {
                ret = max(ret, longestIncreasingPath(matrix, i, j, visited, mem));
            }
        }
        return ret;
    }
    int longestIncreasingPath(vector<vector<int>> &matrix, sz_t x, sz_t y, vector<vector<bool>> &visited, vector<vector<int>> &mem) {
        if (mem[x-1][y-1])
            return mem[x-1][y-1];
        visited[x-1][y-1] = true;
        int x_delta[] = {-1, 0, 1, 0};
        int y_delta[] = {0, -1, 0, 1};
        int c = 1;
        for (int i = 0; i < 4; ++i) {
            int next_x = x_delta[i] + x;
            int next_y = y_delta[i] + y;
            if (next_x == 0 || next_y == 0 || next_x-1 == matrix.size() || next_y-1 == matrix[next_x-1].size()
                    || visited[next_x-1][next_y-1] || matrix[next_x-1][next_y-1] <= matrix[x-1][y-1])
                continue;
            c = max(c, longestIncreasingPath(matrix, next_x, next_y, visited, mem) + 1);
        }
        mem[x-1][y-1] = c;
        // cout << x-1 << "," << y-1 << ": " << c << endl;
        visited[x-1][y-1] = false;
        return c;
    }
};

int main(void)
{
    vector<vector<int>> matrix = {
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1}
    };
    Solution s;
    cout << s.longestIncreasingPath(matrix) << endl;
    return 0;
}
