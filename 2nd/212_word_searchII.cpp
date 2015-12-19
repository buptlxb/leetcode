#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

struct TrieNode {
    bool isWord;
    vector<TrieNode *> children;
    string val;
    TrieNode() : isWord(false), children(26) {}
};

class Trie {
public:
    typedef vector<char>::size_type sz_t;
    Trie() : root(new TrieNode()) {}
    ~Trie() { destory(root); }
    void addWord(const string &word) {
        TrieNode *cur = root;
        for (auto c : word) {
            if (!cur->children[c-'a'])
                cur->children[c-'a'] = new TrieNode();
            cur = cur->children[c-'a'];
        }
        cur->isWord = true;
        cur->val = word;
    }
    vector<string> boardWalk(const vector<vector<char>> &board) {
        if (board.empty())
            return {};
        set<string> tmp;
        vector<vector<bool>> visited(board.size(), vector<bool>(board.front().size()));
        for (sz_t i = 0; i < board.size(); ++i)
            for (sz_t j = 0; j < board[i].size(); ++j) {
                boardWalk(root, board, i, j, visited, tmp);
            }
        return {tmp.begin(), tmp.end()};
    }
    void boardWalk(TrieNode *cur, const vector<vector<char>> &board, sz_t row, sz_t col, vector<vector<bool>> &visited, set<string> &ret) {
        if (visited[row][col])
            return;
        TrieNode *next = cur->children[board[row][col]-'a'];
        if (!next)
            return;
        if (next->isWord)
            ret.insert(next->val);
        visited[row][col] = true;
        if (row > 0)
            boardWalk(next, board, row-1, col, visited, ret);
        if (col > 0)
            boardWalk(next, board, row, col-1, visited, ret);
        if (row+1 < board.size())
            boardWalk(next, board, row+1, col, visited, ret);
        if (col+1 < board[row].size())
            boardWalk(next, board, row, col+1, visited, ret);
        visited[row][col] = false;
    }

private:
    TrieNode *root;
    void destory(TrieNode *cur) {
        if (!cur)
            return;
        for (auto child : cur->children)
            destory(child);
        delete cur;
    }
};

class Solution {
public:
    typedef vector<bool>::size_type sz_t;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie t;
        for (auto word : words) {
            t.addWord(word);
        }
        return t.boardWalk(board);
    }
};

int main(void)
{
    string w[] = {"oath","pea","eat","rain"};
    vector<string> words(w, w+sizeof(w)/sizeof(string));
    char a1[] = {'o','a','a','n'};
    char a2[] = {'e','t','a','e'};
    char a3[] = {'i','h','k','r'};
    char a4[] = {'i','f','l','v'};
    vector<char> v1(a1, a1+sizeof(a1)/sizeof(char));
    vector<char> v2(a2, a2+sizeof(a2)/sizeof(char));
    vector<char> v3(a3, a3+sizeof(a3)/sizeof(char));
    vector<char> v4(a4, a4+sizeof(a4)/sizeof(char));
    vector<vector<char> > board;
    board.push_back(v1);
    board.push_back(v2);
    board.push_back(v3);
    board.push_back(v4);
    vector<string> ret = Solution().findWords(board, words);
    copy(ret.begin(), ret.end(), ostream_iterator<string>(cout, "\n"));
    cout << endl;
    return 0;
}
