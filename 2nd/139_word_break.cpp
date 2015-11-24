#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    typedef string::size_type sz_t;
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        unordered_set<sz_t> us;
        return wordBreak(s, wordDict, 0, us);
    }
    bool wordBreak(string &s, unordered_set<string> &wordDict, sz_t start, unordered_set<sz_t> &us) {
        if (start == s.size())
            return true;
        if (us.count(start))
            return false;
        for (sz_t i = start, iend = s.size(); i < iend; ++i) {
            if (wordDict.count(s.substr(start, i-start+1)) && wordBreak(s, wordDict, i+1, us))
                return true;
        }
        us.insert(start);
        return false;
    }
};

int main(void)
{
    return 0;
}
