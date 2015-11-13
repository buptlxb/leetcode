#include <iostream>
#include <unordered_set>
#include <string>
#include <queue>
#include <cassert>

using namespace std;

class Solution {
public:
    typedef string::size_type sz_t;
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        int ret = 1;
        wordList.insert(endWord);
        queue<string> q;
        q.push(beginWord);
        const sz_t size = beginWord.size();
        string nil(size+1, 0);
        q.push(nil);
        while (!q.empty()) {
            string cur = q.front();
            q.pop();
            if (cur.size() == nil.size())  {
                if (!q.empty()) {
                    ++ret;
                    q.push(nil);
                }
                continue;
            }
            if (cur == endWord)
                return ret;
            for (char c = 'a'; c <= 'z'; ++c) {
                for (sz_t i = 0; i < size; ++i) {
                    if (cur[i] == c)
                        continue;
                    swap(cur[i], c);
                    if (wordList.erase(cur)) {
                        q.push(cur);
                    }
                    swap(cur[i], c);
                }
            }
        }
        return 0;
    }
};

int main(void)
{
    Solution s;
    string a[] = {"hot","dot","dog","lot","log"};
    unordered_set<string> wordList(a, a+sizeof(a)/sizeof(a[0]));
    assert(5 == s.ladderLength("hit", "cog", wordList));
    return 0;
}
