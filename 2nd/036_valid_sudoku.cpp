#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    typedef vector<char>::size_type sz_t;
    bool isValidSudoku(vector<vector<char> >& board) {
        const int len = board.size();
        vector<bool> tmp(len, false);
        vector<vector<bool> > cols(len, tmp);
        vector<vector<bool> > squares(len, tmp);
        for (sz_t i = 0; i < len; ++i) {
            vector<bool> row(len, false);
            for (sz_t j = 0; j < len; ++j) {
                char c = board[i][j];
                if (c == '.')
                    continue;
                c -= '1';
                if (row[c] || cols[j][c] || squares[i/3*3+j/3][c])
                    return false;
                row[c] = true;
                cols[j][c] = true;
                squares[i/3*3+j/3][c] = true;
            }   
        }   
        return true;
    }   
};

int main(void)
{
    return 0;
}
