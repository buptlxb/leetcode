#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    typedef vector<char>::size_type sz_t;
    int numIslands(vector<vector<char> >& grid) {
        int ret = 0;
        if (grid.empty())
            return ret;
        vector<vector<bool> > visited(grid.size(), vector<bool>(grid.front().size()));
        for (sz_t i = 0, iend = grid.size(); i < iend; ++i) {
            for (sz_t j =0, jend = grid[i].size(); j < jend; ++j) {
                if (grid[i][j] != '1' || visited[i][j])
                    continue;
                numIslands(grid, visited, i, j);
                ++ret;
            }
        }
        return ret;
    }
    void numIslands(vector<vector<char> > &grid, vector<vector<bool> > &visited, sz_t row, sz_t col) {
        if (grid[row][col] != '1' || visited[row][col])
            return;
        visited[row][col] = true;
        if (row > 0)
            numIslands(grid, visited, row-1, col);
        if (col > 0)
            numIslands(grid, visited, row, col-1);
        if (row + 1 < grid.size())
            numIslands(grid, visited, row+1, col);
        if (col + 1 < grid[row].size())
            numIslands(grid, visited, row, col+1);
    }
};

int main(void)
{
    return 0;
}
