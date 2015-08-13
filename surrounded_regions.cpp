#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <queue>
#include <functional>

using namespace std;

class Solution {

public:
    typedef vector<char>::size_type s_t;
    typedef vector<pair<s_t, s_t> > Path;
    void solve(vector<vector<char>>& board) {
        s_t m = board.size();
        if (!m)
            return;
        s_t n = board.front().size();
        if (!n)
            return;
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        for (s_t i = 0; i < m; ++i) {
            for (s_t j = 0; j < n; ++j) {
                if (!visited[i][j] && board[i][j] == 'O') {
                    bool isSurrounded = true;
                    Path path = getPath(board, visited, i, j, isSurrounded);
                    if (isSurrounded) {
                        for (auto x : path) {
                            board[x.first][x.second] = 'X';
                        }
                    }
                }
            }
        }
    }
    typedef queue<pair<s_t, s_t> > PointQ;
    Path getPath(vector<vector<char> > &board, vector<vector<bool> > &visited, s_t row, s_t col, bool &isSurrounded) {
        int direct [4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        s_t m = board.size();
        s_t n = board.front().size();
        PointQ q;
        pair<s_t, s_t> start(row, col);
        q.push(start);
        Path path;
        while (!q.empty()) {
            s_t curX = q.front().first;
            s_t curY = q.front().second;
            q.pop();
            if (curX == 0 || curX == m-1 || curY == 0 || curY == n-1)
                isSurrounded = false;
            if (!visited[curX][curY] && board[curX][curY] == 'O') {
                visited[curX][curY] = true;
                pair<s_t, s_t> tmp(curX, curY);
                path.push_back(tmp);
                for (s_t i = 0; i < 4; ++i) {
                    if (curX == 0 && i == 0 || curX == m-1 && i == 1 || curY == 0 && i == 2 || curY == n-1 && i == 3)
                        continue;
                    pair<s_t, s_t> tmp(curX+direct[i][0], curY+direct[i][1]);
                    if (!visited[tmp.first][tmp.second] && board[tmp.first][tmp.second] == 'O')
                        q.push(tmp);
                }
            }
        }
        return path;
    }

};

int main(void)
{
    //vector<vector<char> > board(4, vector<char>(4, 'X'));
    //board[1][1]= 'O';
    //board[1][2]= 'O';
    //board[2][2]= 'O';
    //board[3][1]= 'O';
    vector<vector<char> > board(3, vector<char>(3, 'X'));
    board[1][1] = 'O';
    Solution().solve(board);
    for (auto x : board) {
        copy(x.begin(), x.end(), ostream_iterator<char>(cout, " "));
        cout << endl;
    }
    return 0;
}
