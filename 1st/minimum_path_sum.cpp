#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        vector<int> tmp(grid.front().size(), 0);
        tmp[0] = grid[0][0];
        for (vector<int>::size_type j = 1; j < grid[0].size(); ++j) {
            tmp[j] = tmp[j-1] + grid[0][j];
        }
        for (vector<vector<int> >::size_type i = 1; i < grid.size(); ++i) {
            tmp[0] += grid[i][0];
            for (vector<int>::size_type j = 1; j < grid[i].size(); ++j) {
                tmp[j] = (tmp[j] < tmp[j-1] ? tmp[j] : tmp[j-1]) + grid[i][j];
            }
        }
        return tmp[grid.front().size()-1];
    }
};

int main(void)
{
    int array[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    vector<int> a1(array[0], array[0]+sizeof(array[0])/sizeof(int));
    vector<int> a2(array[1], array[1]+sizeof(array[1])/sizeof(int));
    vector<int> a3(array[2], array[2]+sizeof(array[2])/sizeof(int));
    vector<vector<int> > grid;
    grid.push_back(a1);
    grid.push_back(a2);
    grid.push_back(a3);
    cout << Solution().minPathSum(grid) << endl;
    return 0;
}
