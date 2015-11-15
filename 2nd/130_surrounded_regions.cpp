#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    typedef vector<char>::size_type sz_t;
    void solve(vector<vector<char> >& board) {
        vector<vector<bool> > visited(board.size(), vector<bool>(board.front().size()));
        vector<vector<bool> > unchanged(visited);
        for (sz_t i = 0, iend = board.size(); i < iend; ++i) {
            if (board[i][0] == 'O' && !visited[i][0])
                dfs(board, visited, unchanged, i, 0);
            if (board[i][board[i].size()-1] == 'O' && !visited[i][board[i].size()-1])
                dfs(board, visited, unchanged, i, board[i].size()-1);
        }
        for (sz_t i = 0, iend = board.front().size(); i < iend; ++i) {
            if (board[0][i] == 'O' && !visited[0][i])
                dfs(board, visited, unchanged, 0, i);
            if (board[board.size()-1][i] == 'O' && !visited[board.size()-1][i])
                dfs(board, visited, unchanged, board.size()-1, i);
        }
        flip(board, unchanged);
    }
    void dfs(vector<vector<char> > &board, vector<vector<bool> > &visited, vector<vector<bool> > &unchanged, sz_t i, sz_t j) {
        visited[i][j] = unchanged[i][j] = true;
        if (i > 0 && board[i-1][j] == 'O' && !visited[i-1][j])
            dfs(board, visited, unchanged, i-1, j);
        if (j > 0 && board[i][j-1] == 'O' && !visited[i][j-1])
            dfs(board, visited, unchanged, i, j-1);
        if (i+1 < board.size() && board[i+1][j] == 'O' && !visited[i+1][j])
            dfs(board, visited, unchanged, i+1, j);
        if (j+1 < board[i].size() && board[i][j+1] == 'O' && !visited[i][j+1])
            dfs(board, visited, unchanged, i, j+1);
    }
    void flip(vector<vector<char> > &board, vector<vector<bool> > &unchanged) {
        for (sz_t i = 0, iend = board.size(); i < iend; ++i) {
            for (sz_t j = 0, jend  = board[i].size(); j < jend; ++j) {
                if (board[i][j] == 'X' || unchanged[i][j])
                    continue;
                board[i][j] = 'X';
            }
        }
    }
};

int main(void)
{
    string line;
    vector<vector<char> > v;
    while (cin >> line) {
        vector<char> t(line.begin(), line.end());
        v.push_back(t);
    }
    cout << v.size() << " " << v.front().size() << endl;
    Solution().solve(v);
    return 0;
}
