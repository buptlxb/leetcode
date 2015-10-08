#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef vector<vector<char> >::size_type sz_t;
    bool exist(vector<vector<char> > &board, string word) {
        if (word.size() == 0)
            return true;
        char used = -1;
        for (sz_t i = 0, iend = board.size(); i < iend; ++i) {
            for (sz_t j = 0, jend = board[i].size(); j < jend; ++j) {
                if (board[i][j] == word[0]) {
                    swap(used, board[i][j]);
                    if (exist(board, i, j, word, 0))
                        return true;
                    swap(used, board[i][j]);
                }
            }
        }
        return false;
    }
    bool exist(vector<vector<char> > &board, sz_t row, sz_t col, const string &word, sz_t index) {
        if (index+1 == word.size())
            return true;
        char used = -1;
        if (row != 0 && word[index+1] == board[row-1][col]) {
            swap(used, board[row-1][col]);
            if (exist(board, row-1, col, word, index+1))
                return true;
            swap(used, board[row-1][col]);
        }
        if (row+1 != board.size() && word[index+1] == board[row+1][col]) {
            swap(used, board[row+1][col]);
            if (exist(board, row+1, col, word, index+1))
                return true;
            swap(used, board[row+1][col]);
        }
        if (col != 0 && word[index+1] == board[row][col-1]) {
            swap(used, board[row][col-1]);
            if (exist(board, row, col-1, word, index+1))
                return true;
            swap(used, board[row][col-1]);
        }
        if (col+1 != board[row].size() && word[index+1] == board[row][col+1]) {
            swap(used, board[row][col+1]);
            if (exist(board, row, col+1, word, index+1))
                return true;
            swap(used, board[row][col+1]);
        }
        return false;
    }
};

int main(void)
{
    return 0;
}
