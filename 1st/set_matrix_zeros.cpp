#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type s_t;
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstRow(false), firstCol(false);
        for (s_t i = 0, iend = matrix.size(); i < iend; ++i) {
            if (!matrix[i][0])
                firstCol = true;
        }
        for (s_t i = 0, iend = matrix.front().size(); i < iend; ++i) {
            if (!matrix[0][i])
                firstRow = true;
        }
        for (s_t i = 1, iend = matrix.size(); i < iend; ++i) {
            for (s_t j = 1, jend = matrix.front().size(); j < jend; ++j) {
                if (matrix[i][j])
                    continue;
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
        for (s_t i = 1, iend = matrix.size(); i < iend; ++i) {
            if (!matrix[i][0])
                matrix[i].assign(matrix[i].size(), 0);
        }
        for (s_t i = 1, iend = matrix.front().size(); i < iend; ++i) {
            if (matrix[0][i])
                continue;
            for (s_t j = 0, jend = matrix.size(); j < jend; ++j) {
                matrix[j][i] = 0;
            }
        }
        if (firstRow) {
            matrix.front().assign(matrix.front().size(), 0);
        }
        if (firstCol) {
            for (s_t j = 0, jend = matrix.size(); j < jend; ++j) {
                matrix[j][0] = 0;
            }
        }
    }
};

int main(void)
{
    return 0;
}
