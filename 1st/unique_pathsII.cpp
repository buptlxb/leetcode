#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        vector<int> tmp(obstacleGrid.front().size(), 0);
        tmp[0] = 1;
        for (vector<vector<int> >::size_type i = 0; i < obstacleGrid.size(); ++i) {
            if (obstacleGrid[i][0])
                tmp[0] = 0;
            for (vector<int>::size_type j = 1; j < obstacleGrid[i].size(); ++j) {
                if (obstacleGrid[i][j])
                    tmp[j] = 0;
                else
                    tmp[j] += tmp[j-1];
            }
        }
        return tmp[obstacleGrid.front().size()-1];
    }
};

int main(void)
{
    int array[3][3] = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    vector<int> a1(array[0], array[0]+sizeof(array[0])/sizeof(int));
    vector<int> a2(array[1], array[1]+sizeof(array[0])/sizeof(int));
    vector<int> a3(array[2], array[2]+sizeof(array[0])/sizeof(int));
    vector<vector<int> > obstacleGrid;
    obstacleGrid.push_back(a1);
    obstacleGrid.push_back(a2);
    obstacleGrid.push_back(a3);
    cout << Solution().uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}
