#include <iostream>
#include <unordered_set>
#include <string>
#include <cassert>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    typedef string::size_type sz_t;
    vector<vector<string> > findLadders(string beginWord, string endWord, unordered_set<string>& wordList) {
        wordList.insert(endWord);
        vector<vector<string> > ret;
        const sz_t size = beginWord.size();
        map<string, unordered_set<string> > prevMap;
        vector<unordered_set<string> > candidates(2);
        int cur = 0;
        candidates[cur].insert(beginWord);
        while (true) {
            cur = 1 - cur;
            for (auto str : candidates[1-cur])
                wordList.erase(str);
            candidates[cur].clear();
            for (auto str : candidates[1-cur]) {
                for (sz_t i = 0; i < size; ++i) {
                    string w = str;
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (w[i] == c)
                            continue;
                        w[i] = c;
                        if (wordList.count(w)) {
                            prevMap[w].insert(str);
                            candidates[cur].insert(w);
                        }
                    }
                }
            }
            if (candidates[cur].size() == 0) {
                return ret;
            }
            if (candidates[cur].count(endWord))
                break;
        }
        vector<string> tmp(1, endWord);
        recoverPath(endWord, beginWord, prevMap, tmp, ret);
        return ret;
    }
    void recoverPath(string beginWord, string endWord, map<string, unordered_set<string> > &m, vector<string> &tmp, vector<vector<string> > &ret) {
        if (beginWord == endWord) {
            ret.push_back(vector<string>(tmp.rbegin(), tmp.rend()));
        } else {
            for (unordered_set<string>::iterator i = m[beginWord].begin(), iend = m[beginWord].end(); i != iend; ++i) {
                tmp.push_back(*i);
                recoverPath(*i, endWord, m, tmp, ret);
                tmp.pop_back();
            }
        }
    }
};

int main(void)
{
    Solution s;
    string a[] = {
        "hot","dot","dog","lot","log"
    };
    unordered_set<string> wordList(a, a+sizeof(a)/sizeof(a[0]));
    vector<vector<string> > ret = s.findLadders("hit", "cog", wordList);
    for (int i = 0; i < ret.size(); ++i) {
        for (int j = 0; j < ret[i].size(); ++j) {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
