#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef vector<char>::size_type s_t;
    bool exist(vector<vector<char> >& board, string word) {
        if (word.empty())
            return true;
        for (s_t i = 0, iend = board.size(); i < iend; ++i) {
            for (s_t j = 0, jend = board[i].size(); j < jend; ++j) {
                if (word[0] == board[i][j]) {
                    char tmp = 0;
                    swap(board[i][j], tmp);
                    if (exist(board, word, i, j, 1))
                        return true;
                    swap(board[i][j], tmp);
                }
            }
        }
        return false;
    }
    bool exist(vector<vector<char> > &board, const string &word, s_t i, s_t j, s_t index) {
        if (index == word.size()) {
            return true;
        } else {
            if (i > 0 && board[i-1][j] != 0 && board[i-1][j] == word[index]) {
                char tmp = 0;
                swap(board[i-1][j], tmp);
                if (exist(board, word, i-1, j, index+1))
                    return true;
                swap(board[i-1][j], tmp);
            }

            if (j > 0 && board[i][j-1] != 0 && board[i][j-1] == word[index]) {
                char tmp = 0;
                swap(board[i][j-1], tmp);
                if (exist(board, word, i, j-1, index+1))
                    return true;
                swap(board[i][j-1], tmp);
            }

            if (i+1 < board.size() && board[i+1][j] != 0 && board[i+1][j] == word[index]) {
                char tmp = 0;
                swap(board[i+1][j], tmp);
                if (exist(board, word, i+1, j, index+1))
                    return true;
                swap(board[i+1][j], tmp);
            }

            if (j+1 < board[i].size() && board[i][j+1] != 0 && board[i][j+1] == word[index]) {
                char tmp = 0;
                swap(board[i][j+1], tmp);
                if (exist(board, word, i, j+1, index+1))
                    return true;
                swap(board[i][j+1], tmp);
            }
            return false;
        }
    }
};

int main(void)
{
    string s1 = "A";
    string s2 = "SFCS";
    string s3 = "ADEE";
    vector<vector<char> > board;
    board.push_back(vector<char>(s1.begin(), s1.end()));
    //board.push_back(vector<char>(s2.begin(), s2.end()));
    //board.push_back(vector<char>(s3.begin(), s3.end()));
    cout << Solution().exist(board, "A") << endl;
    return 0;
}
