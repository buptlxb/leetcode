#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return searchMatrix(matrix, 0, 0, matrix.size()-1, matrix.front().size()-1, target);
    }   
    bool searchMatrix(vector<vector<int>> &matrix, int A, int B, int C, int D, int target) {
        if (A > C || B > D)
            return false;
        int m = (A + C) >> 1;
        int n = (B + D) >> 1;  
        if (matrix[m][n] == target)
            return true;
        if (matrix[m][n] < target)
            return searchMatrix(matrix, m+1, B, C, n, target) || searchMatrix(matrix, A, n+1, C, D, target);                                                                  
        return searchMatrix(matrix, A, n, m-1, D, target) || searchMatrix(matrix, A, B, C, n-1, target);
    }   
};

int main(void)
{
    vector<vector<int>> matrix{{-1}, {-1}};
    cout << Solution().searchMatrix(matrix, -1) << endl;
    return 0;
}
