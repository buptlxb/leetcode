#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

struct WordDictionaryItem {
    bool isWord;
    vector<WordDictionaryItem *> children;
    WordDictionaryItem () : isWord(false), children(26) {}
};

class WordDictionary {
public:
    WordDictionary() : root(new WordDictionaryItem()) {}
    ~WordDictionary() { destroy(root); }

    // Adds a word into the data structure.
    void addWord(string word) {
        WordDictionaryItem *cur = root;
        for (auto c : word) {
            if (!cur->children[c-'a'])
                cur->children[c-'a'] = new WordDictionaryItem();
            cur = cur->children[c-'a'];
        }
        cur->isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return search(word.begin(), word.end(), root);
    }
    bool search(string::iterator first, string::iterator last, WordDictionaryItem *cur) {
        for (; first != last; ++first) {
            if (*first == '.') {
                for (auto child : cur->children) {
                    if (child && search(first+1, last, child))
                        return true;
                }
                return false;
            } else if (cur->children[*first-'a']) {
                cur = cur->children[*first-'a'];
            } else
                return false;
        }
        return cur->isWord;
    }
private:
    void destroy(WordDictionaryItem *root) {
        if (!root)
            return;
        for (auto item : root->children)
            destroy(item);
        delete root;
    }
private:
    WordDictionaryItem *root;
};

int main(void)
{
    WordDictionary wd;
    wd.addWord("a");
    wd.addWord("a");
    assert(wd.search("."));
    assert(wd.search("a"));
    assert(!wd.search("aa"));
    assert(!wd.search(".a"));
    assert(!wd.search("a."));
    wd.addWord("bad");
    wd.addWord("dad");
    wd.addWord("mad");
    assert(!wd.search("pad"));
    assert(wd.search("bad"));
    assert(wd.search(".ad"));
    assert(wd.search("b.."));
    return 0;
}
