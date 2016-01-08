#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type sz_t;
    void gameOfLife(vector<vector<int>>& board) {
        vector<int> x{-1, -1, -1, 0, 0, 1, 1, 1}; 
        vector<int> y{-1, 0, 1, -1, 1, -1, 0, 1}; 
        for (sz_t i = 1, iend = board.size(); i <= iend; ++i) {
            for (sz_t j = 1, jend = board[i-1].size(); j <= jend; ++j) {
                int cnt = 0;
                for (sz_t k = 0, kend = x.size(); k < kend; ++k) {
                    sz_t next_x = i + x[k];
                    sz_t next_y = j + y[k];
                    if (!next_x || !next_y || next_x == iend+1 || next_y == jend+1)
                        continue;
                    cnt += board[next_x-1][next_y-1] & 0x1;
                }   
                if (board[i-1][j-1] && cnt < 2)
                    board[i-1][j-1] |= 0x2;
                else if (!board[i-1][j-1] && cnt == 3)
                    board[i-1][j-1] |= 0x2;
                else if (board[i-1][j-1] == 1 && cnt < 4)
                    ;   
                else if (board[i-1][j-1] == 1)
                    board[i-1][j-1] |= 0x2;
            }   
        }   
        for (sz_t i = 0, iend = board.size(); i < iend; ++i) {
            for (sz_t j = 0, jend = board[i].size(); j < jend; ++j) {
                if (board[i][j] == 2)
                    board[i][j] = 1;
                else if (board[i][j] == 3)
                    board[i][j] = 0;
            }   
        }   
    }   
};

int main(void)
{
    vector<vector<int>> board{{0,0,0,0,1},{0,0,0,0,0},{1,0,0,0,1}};
    Solution().gameOfLife(board);
    return 0;
}
