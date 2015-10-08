#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type sz_t;
    void setZeroes(vector<vector<int> >& matrix) {
        if (matrix.empty())
            return;
        bool isFirstColZero = false;
        bool isFirstRowZero = false;
        for (sz_t i = 0, iend = matrix.size(); i < iend; ++i) {
            if (matrix[i][0])
                continue;
            isFirstColZero = true;
            break;
        }
        for (sz_t i = 0, iend = matrix[0].size(); i < iend; ++i) {
            if (matrix[0][i])
                continue;
            isFirstRowZero = true;
            break;
        }
        for (sz_t i = 1, iend = matrix.size(); i < iend; ++i) {
            for (sz_t j = 1, jend = matrix[i].size(); j < jend; ++j) {
                if (matrix[i][j])
                    continue;
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
        for (sz_t i = 1, iend = matrix.size(); i < iend; ++i) {
            for (sz_t j = 1, jend = matrix[i].size(); j < jend; ++j) {
                if (matrix[i][0] && matrix[0][j])
                    continue;
                matrix[i][j] = 0;
            }
        }
        if (isFirstColZero) {
            for (sz_t i = 0, iend = matrix.size(); i < iend; ++i) {
                matrix[i][0] = 0;
            }
        }
        if (isFirstRowZero) {
            for (sz_t i = 0, iend = matrix[0].size(); i < iend; ++i) {
                matrix[0][i] = 0;
            }
        }
    }
};

int main(void)
{
    return 0;
}
