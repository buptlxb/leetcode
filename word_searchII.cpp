#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <set>

using namespace std;

struct TrieNode {
    TrieNode() :isKey(false), children(26, NULL) { }
    bool isKey;
    string str;
    vector<TrieNode *> children;
};

class Trie {
    public:
        Trie () : root(new TrieNode()) { }
        typedef string::size_type s_t;
        void addWord(string s) {
            TrieNode *pos = root;
            for (s_t i = 0, iend = s.size(); i < iend; ++i) {
                if (!pos->children[s[i]-'a'])
                    pos->children[s[i]-'a'] = new TrieNode();
                pos = pos->children[s[i]-'a'];
            }
            pos->isKey = true;
            pos->str = s;
        }
        void walk(vector<vector<char> > &board, s_t i, s_t j, vector<vector<bool> > &used, set<string> &ret) {
            walk(root, board, i, j, used, ret);
        }
        void walk(TrieNode *root, vector<vector<char> > &board, s_t i, s_t j, vector<vector<bool> > &used, set<string> &ret) {
            TrieNode *child = root->children[board[i][j]-'a'];
            if (!child)
                return;
            if (child->isKey)
                ret.insert(child->str);
            used[i][j] = true;
            if (i > 0 && !used[i-1][j])
                walk(child, board, i-1, j, used, ret);
            if (j > 0 && !used[i][j-1])
                walk(child, board, i, j-1, used, ret);
            if (i+1 < board.size() && !used[i+1][j])
                walk(child, board, i+1, j, used, ret);
            if (j+1 < board[i].size() && !used[i][j+1])
                walk(child, board, i, j+1, used, ret);
            used[i][j] = false;
        }
    private:
        TrieNode *root;
};

class Solution {
public:
    typedef string::size_type s_t;
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        if (board.empty())
            return vector<string>();
        Trie t;
        vector<bool> tmp(board.front().size(), false);
        for (auto w : words)
            t.addWord(w);
        set<string> ret;
        for (s_t i = 0, iend = board.size(); i < iend; ++i) {
            for (s_t j = 0, jend = board[i].size(); j < jend; ++j) {
                vector<vector<bool> > used(board.size(), tmp);
                t.walk(board, i, j, used, ret);
            }
        }
        return vector<string>(ret.begin(), ret.end());
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
