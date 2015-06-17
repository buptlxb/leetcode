#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    typedef vector<vector<char> >::size_type Row;
    typedef vector<char>::size_type Col;
    bool isValid(const vector<vector<char> > &board, Row x, Col y) {
        for (Col i = 0; i < 9; ++i) {
            if (i != y && board[x][y] == board[x][i])
                return false;
        }
        for (Row i = 0; i < 9; ++i) {
            if (i != x && board[x][y] == board[i][y])
                return false;
        }
        for (Row i = 0; i < 3; ++i) {
            for (Col j = 0; j < 3; ++j) {
                Row r = i + x/3*3;
                Col c = j + y/3*3;
                if (x != r && y != c && board[x][y] == board[r][c])
                    return false;
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char> >& board) {
        solveSudoku(board, 0, 0);
    }
    bool solveSudoku(vector<vector<char> >& board, Row x, Col y) {
        if (y >= 9)
            return solveSudoku(board, x+1, 0);
        if (x == 9)
            return true;
        if (board[x][y] == '.') {
            for (int i = 0; i < 9; ++i) {
                board[x][y] = '1' + i;
                if (isValid(board, x, y)) {
                    if (solveSudoku(board, x, y+1))
                        return true;
                }
                board[x][y] = '.';
            }
        } else
            return solveSudoku(board, x, y+1);
        return false;
    }
};

ostream & operator<< (ostream &os, const vector<vector<char> > &board)
{
    for (vector<vector<char> >::const_iterator i = board.begin(), iend = board.end(); i != iend; ++i) {
        os << string(19, '-') << endl;
        os << "|";
        for (vector<char>::const_iterator j = i->begin(), jend = i->end(); j != jend; ++j) {
            os << *j << "|";
        }
        os << endl;
    }
    os << string(19, '-') << endl;
    return os;
}

int main(void)
{
    vector<vector<char> > board;
    const char size = 9;
    char array[size][size] = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    vector<char> tmp;
    for (char i = 0; i < size; ++i) {
        for (char j = 0; j < size; ++j) {
            tmp.push_back(array[i][j]);
        }
        board.push_back(tmp);
        tmp.clear();
    }
    Solution().solveSudoku(board);
    cout << board << endl;
    return 0;
}
