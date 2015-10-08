#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        int ret = 0;
        vector<int> board(n);
        solveNQueens(0, board, ret);
        return ret;
    }
    void solveNQueens(int k, vector<int> &board, int &ret) {
        if (k == board.size()) {
            ++ret;
            return;
        }
        for (int i = 0, iend = board.size(); i < iend; ++i) {
            if (isValid(board, k, i)) {
                board[k] = i;
                solveNQueens(k+1, board, ret);
            }
        }
    }
    bool isValid(vector<int> &board, int k, int m) {
        for (int i = 0; i < k; ++i) {
            if (board[i] == m || k - i == m - board[i] || k - i == board[i] - m)
                return false;
        }
        return true;
    }
};

int main(void)
{
    cout << Solution().totalNQueens(4) << endl;
    return 0;
}
