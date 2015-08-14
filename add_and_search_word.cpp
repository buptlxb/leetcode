#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct TrieNode {
    TrieNode() : is_key(false), children(26, NULL) { }
    bool is_key;
    vector<TrieNode *> children;
};

class WordDictionary {
public:
    WordDictionary () : root(new TrieNode()) { }

    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *pos = root;
        for (string::iterator i = word.begin(), iend = word.end(); i != iend; ++i) {
            if (!pos->children[*i-'a'])
                pos->children[*i-'a'] = new TrieNode();
            pos = pos->children[*i-'a'];
        }
        pos->is_key = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        queue<TrieNode *> q;
        q.push(root);
        q.push(NULL);
        for (string::iterator i = word.begin(), iend = word.end(); i != iend; ++i) {
            while (!q.empty()) {
                TrieNode *pos = q.front();
                q.pop();
                if (pos == NULL) {
                    if (!q.empty())
                        q.push(NULL);
                    break;
                }
                if (*i == '.') {
                    for (char c = 'a'; c <= 'z'; ++c)
                        if (pos->children[c-'a'])
                            q.push(pos->children[c-'a']);
                } else if (!pos->children[*i-'a'])
                    ;
                else
                    q.push(pos->children[*i-'a']);
            }
        }
        while (!q.empty()) {
            if (q.front() && q.front()->is_key)
                return true;
            q.pop();
        }
        return false;
    }
    TrieNode *root;
};

int main(void) {
    // Your WordDictionary object will be instantiated and called as such:
    WordDictionary wordDictionary;
    wordDictionary.addWord("word");
    wordDictionary.addWord("ward");
    wordDictionary.addWord("wacd");
    wordDictionary.addWord("ware");
    cout << boolalpha << wordDictionary.search("pattern") << endl;
    cout << wordDictionary.search("word") << endl;
    cout << wordDictionary.search("w.r.") << endl;
    return 0;
}
