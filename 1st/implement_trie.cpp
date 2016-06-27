#include <iostream>
#include <map>
#include <vector>

using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() : is_key(false), children(26, NULL) { }
    vector<TrieNode *> children;
    bool is_key;
};

class Trie {
public:
    typedef string::size_type s_t;
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *pos = root;
        for (s_t i = 0, iend = word.size(); i < iend; ++i) {
            if (!pos->children[word[i]-'a'])
                pos->children[word[i]-'a'] = new TrieNode();
            pos = pos->children[word[i]-'a'];
        }
        pos->is_key = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *pos = root;
        for (s_t i = 0, iend = word.size(); i < iend; ++i) {
            if (!pos->children[word[i]-'a'])
                return false;
            pos = pos->children[word[i]-'a'];
        }
        return pos->is_key;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *pos = root;
        for (s_t i = 0, iend = prefix.size(); i < iend; ++i) {
            if (!pos->children[prefix[i]-'a'])
                return false;
            pos = pos->children[prefix[i]-'a'];
        }
        return true;
    }

private:
    TrieNode* root;
};

int main(void) {
    // Your Trie object will be instantiated and called as such:
    Trie trie;
    trie.insert("somestring");
    cout << trie.search("key") << endl;;
    trie.insert("key");
    cout << trie.search("key") << endl;;
    cout << trie.startsWith("key") << endl;;
    cout << trie.startsWith("some") << endl;;
    cout << trie.search("some") << endl;;
    trie.insert("ab");
    cout << trie.search("a") << endl;;
    return 0;
}


