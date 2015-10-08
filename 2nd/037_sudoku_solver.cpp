#include <iostream>
#include <vector>

using namespace std;

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


class Solution {
public:
    typedef vector<char>::size_type sz_t;
    void solveSudoku(vector<vector<char> > &board) {
        solveSudoku(board, 0, 0);
    }
    bool solveSudoku(vector<vector<char> > &board, sz_t a, sz_t b) {
        const int len = board.size();
        if (a == len && b == 0)
            return true;
        for (sz_t i = a; i < len; ++i) {
            for (sz_t j = b; j < len; ++j) {
                if (board[i][j] != '.')
                    continue;
                for (char c = '1'; c <= '9'; ++c) {
                    if (isvalid(board, i, j, c)) {
                        board[i][j] = c;
                        if (solveSudoku(board, i+(j+1)/len, (j+1)%len)) {
                            //cout << board << endl;
                            return true;
                        }
                    }
                }
                board[i][j] = '.';
                return false;
            }
            b = 0;
        }
        return true;
    }
    bool isvalid(vector<vector<char> > &board, sz_t a, sz_t b, char c) {
        const int len = board.size();
        for (sz_t i = 0; i < len; ++i) {
            if (board[a][i] == c || board[i][b] == c)
                return false;
        }
        for (sz_t i = 0; i < len/3; ++i) {
            for (sz_t j = 0; j < len/3; ++j) {
                if (board[i+a/3*3][j+b/3*3] == c)
                    return false;
            }
        }
        return true;
    }   
};

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
