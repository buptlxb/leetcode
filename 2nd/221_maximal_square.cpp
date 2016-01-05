#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type sz_t;
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;
        vector<vector<int>> board(matrix.size(), vector<int>(matrix.front().size()));
        int ret = 0;
        for (sz_t i = matrix.size(); i > 0; --i) {
            board[i-1].back() = matrix[i-1].back() == '1';
            ret = max(ret, board[i-1].back());
        }
        for (sz_t i = matrix.back().size(); i > 0; --i) {
            board.back()[i-1] = matrix.back()[i-1] == '1';
            ret = max(ret, board.back()[i-1]);
        }
        for (sz_t i = matrix.size()-1; i > 0; --i) {
            for (sz_t j = matrix[i-1].size()-1; j > 0; --j) {
                board[i-1][j-1] = matrix[i-1][j-1] == '1' ? 1 + min(board[i][j], min(board[i-1][j], board[i][j-1])) : 0;
                ret = max(ret, board[i-1][j-1]);
            }
        }
        return ret;
    }
};

int main(void)
{
    return 0;
}
