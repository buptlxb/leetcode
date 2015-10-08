#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type sz_t;
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix(n, vector<int>(n));
        spiralOrder(matrix, 0, 0, 1);
        return matrix;
    }
    void spiralOrder(vector<vector<int> > &matrix, sz_t a, sz_t b, int x) {
        if (a + a + 1 > matrix.size())
            return;
        if (a + a + 1 == matrix.size()) {
            for (sz_t i = b, iend = matrix[a].size()-b; i < iend; ++i)
                matrix[a][i] = x++;
            return;
        }   
        if (b + b + 1 > matrix[a].size())  
            return;
        if (b + b + 1 == matrix[a].size()) {
            for (sz_t i = a, iend = matrix.size() - a; i < iend; ++i) {
                matrix[i][b] = x++;
            }   
            return;
        }   
        for (sz_t i = b, iend = matrix[a].size()-b; i < iend; ++i)
            matrix[a][i] = x++;
        for (sz_t i = a+1, iend = matrix.size() - a - 1; i < iend; ++i) {
            matrix[i][matrix[a].size()-b-1] = x++;
        }   
        for (sz_t i = matrix[a].size()-b; i > b; --i)
            matrix[matrix.size()-a-1][i-1] = x++;
        for (sz_t i = matrix.size()-a-1; i > a+1; --i) {
            matrix[i-1][b] = x++;
        }   
        spiralOrder(matrix, a+1, b+1, x);
    }   
};

int main(void)
{
    vector<vector<int> > ret = Solution().generateMatrix(3);
    for (vector<int>::size_type i = 0, iend = ret.size(); i < iend; ++i) {
        for (vector<int>::size_type j = 0, jend = ret.size(); j < jend; ++j) {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
