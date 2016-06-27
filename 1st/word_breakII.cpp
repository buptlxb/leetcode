#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <sstream>

using namespace std;

class Solution {

public:
    typedef string::size_type s_t;
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        unordered_set<string> unmatch;
        vector<s_t> tmp;
        vector<string> ret;
        wordBreak(s, wordDict, 0, unmatch, tmp, ret);
        return ret;
    }

    bool wordBreak(const string &s, const unordered_set<string> &wordDict, s_t start, unordered_set<string> &unmatch, vector<s_t> &tmp, vector<string> &ret) {
        if (start == s.size()) {
            ostringstream os;
            for (s_t i = 1, iend = tmp.size(); i < iend; ++i) {
                os << s.substr(tmp[i-1], tmp[i]-tmp[i-1]) << " ";
            }
            os << s.substr(tmp.back());
            ret.push_back(os.str());
            return true;
        }
        bool flag = false;
        for (s_t i = start, iend = s.size(); i < iend; ++i) {
            if (wordDict.find(s.substr(start, i-start+1)) != wordDict.end()) {
                if (unmatch.find(s.substr(i+1)) != unmatch.end())
                    continue;
                tmp.push_back(start);
                //wordBreak(s, wordDict, i+1, unmatch, tmp, ret);
                if (wordBreak(s, wordDict, i+1, unmatch, tmp, ret)) {
                    flag = true;
                } else
                    unmatch.insert(s.substr(i+1));
                tmp.pop_back();
            }
        }
        return flag;
    }

};

int main(void)
{
    string array[] = {"cat", "cats", "and", "sand", "dog"};
    unordered_set<string> dict(array, array+sizeof(array)/sizeof(string));
    vector<string> ret = Solution().wordBreak("catsanddog", dict);
    copy(ret.begin(), ret.end(), ostream_iterator<string>(cout, "\n"));
    cout << endl;
    return 0;
}
