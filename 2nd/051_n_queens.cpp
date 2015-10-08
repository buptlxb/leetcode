#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > ret;
        vector<int> board(n);
        solveNQueens(0, board, ret);
        return ret;
    }
    void solveNQueens(int k, vector<int> &board, vector<vector<string> > &ret) {
        if (k == board.size()) {
            vector<string>  tmp;
            for (auto x : board) {
                string row(board.size(), '.');
                row[x] = 'Q';
                tmp.push_back(row);
            }
            ret.push_back(tmp);
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
    vector<vector<string> > ret = Solution().solveNQueens(4);
    for (auto board : ret) {
        for (auto s : board) {
            cout << s << endl;
        }
        cout << endl;
    }
    return 0;
}
