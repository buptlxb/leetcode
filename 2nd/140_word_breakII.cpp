#include <iostream>
#include <vector>
#include <unordered_set>
#include <sstream>

using namespace std;

class Solution {
public:
    typedef string::size_type sz_t;
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> tmp, ret;
        unordered_set<sz_t> us;
        wordBreak(s, wordDict, 0, tmp, ret, us);
        return ret;
    }
    bool wordBreak(string &s, unordered_set<string> &wordDict, sz_t start, vector<string> &tmp, vector<string> &ret, unordered_set<sz_t> &us) {
        if (start == s.size()) {
            string t = join(' ', tmp);
            ret.push_back(t);
            return true;
        }
        if (us.count(start))
            return false;
        bool flag = false;
        for (sz_t i = start, iend = s.size(); i < iend; ++i) {
            string t = s.substr(start, i-start+1);
            if (wordDict.count(t)) {
                tmp.push_back(t);
                if (wordBreak(s, wordDict, i+1, tmp, ret, us))
                    flag = true;
                tmp.pop_back();
            }
        }
        if (!flag)
            us.insert(start);
        return flag;
    }
    string join(char c, vector<string> &tmp) {
        if (tmp.empty())
            return string();
        ostringstream os;
        os << tmp.front();
        for (sz_t i = 1, iend = tmp.size(); i < iend; ++i)
            os << c << tmp[i];
        return os.str();
    }
};

int main(void)
{
    return 0;
}
