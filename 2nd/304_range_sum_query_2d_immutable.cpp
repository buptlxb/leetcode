#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
    vector<vector<int>> sums;
public:
    typedef vector<int>::size_type sz_t;
    NumMatrix(vector<vector<int>> &matrix) : sums(matrix.size()+1) {
        for (sz_t i = 0, iend = matrix.size(); i < iend; ++i) {
            if (i == 0)
                sums[i].resize(matrix[i].size()+1);
            sums[i+1].resize(matrix[i].size()+1);
            for (sz_t j = 0, jend = matrix[i].size(); j < jend; ++j) {
                sums[i+1][j+1] = matrix[i][j] + sums[i][j+1] + sums[i+1][j] - sums[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2+1][col2+1] - sums[row1][col2+1] - sums[row2+1][col1] + sums[row1][col1];
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
int main(void)
{
    vector<vector<int>> matrix = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };
    NumMatrix nm(matrix);

    cout << nm.sumRegion(2, 1, 4, 3) << endl; // -> 8
    cout << nm.sumRegion(1, 1, 2, 2) << endl; // -> 11
    cout << nm.sumRegion(1, 2, 2, 4) << endl; // -> 12

    return 0;
}
