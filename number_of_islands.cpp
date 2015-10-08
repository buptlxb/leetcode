#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    typedef vector<char>::size_type s_t;
    int numIslands(vector<vector<char> >& grid) {
        if (grid.empty())
            return 0;
        vector<bool> tmp(grid.front().size(), false);
        vector<vector<bool> > selected(grid.size(), tmp);
        int ret = 0;
        for (s_t i = 0, iend = grid.size(); i < iend; ++i) {
            for (s_t j = 0, jend = grid[i].size(); j < jend; ++j) {
                if (grid[i][j] == '1' && !selected[i][j]) {
                    ++ret;
                    island(grid, selected, i, j);
                    print(selected);
                }
            }
        }
        return ret;
    }
    void island(vector<vector<char> > &grid, vector<vector<bool> > &selected, s_t i, s_t j) {
        selected[i][j] = true;
        if (i > 0 && grid[i-1][j] == '1' && !selected[i-1][j])
            island(grid, selected, i-1, j);
        if (j > 0 && grid[i][j-1] == '1' && !selected[i][j-1])
            island(grid, selected, i, j-1);
        if (i+1 < grid.size() && grid[i+1][j] == '1' && !selected[i+1][j])
            island(grid, selected, i+1, j);
        if (j+1 < grid[i].size() && grid[i][j+1] == '1' && !selected[i][j+1])
            island(grid, selected, i, j+1);
    }
    void print(vector<vector<bool> > &selected) {
        for (s_t i = 0, iend = selected.size(); i < iend; ++i) {
            for (s_t j = 0, jend = selected[i].size(); j < jend; ++j) {
                cout << selected[i][j] << " ";
            }
            cout << endl;
        }
    }
};


int main(void)
{
    char array[][5] = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'},
    };
    vector<char> v0(array[0], array[0]+5);
    vector<char> v1(array[1], array[1]+5);
    vector<char> v2(array[2], array[2]+5);
    vector<char> v3(array[3], array[3]+5);
    vector<vector<char> > grid;
    grid.push_back(v0);
    grid.push_back(v1);
    grid.push_back(v2);
    grid.push_back(v3);
    cout << Solution().numIslands(grid) << endl;
    return 0;
}
