#include <iostream>
#include <vector>

using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() :isWord(false), children(26, NULL) {
    }
    bool isWord;
    vector<TrieNode *> children;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *cur = root;
        for (auto c : word) {
            if (!cur->children[c-'a'])
                cur->children[c-'a'] = new TrieNode();
            cur = cur->children[c-'a'];
        }
        cur->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *cur = root;
        for (auto c : word) {
            if (!cur->children[c-'a'])
                return false;
            cur = cur->children[c-'a'];
        }
        return cur->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *cur = root;
        for (auto c : prefix) {
            if (!cur->children[c-'a'])
                return false;
            cur = cur->children[c-'a'];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main(void)
{
    return 0;
}
