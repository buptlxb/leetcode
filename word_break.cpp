#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {

public:
    typedef string::size_type s_t;
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        unordered_set<string> unmatch;
        return wordBreak(s, wordDict, 0, unmatch);
    }

    bool wordBreak(const string &s, const unordered_set<string> &wordDict, s_t start, unordered_set<string> &unmatch) {
        if (start == s.size())
            return true;
        for (s_t i = start, iend = s.size(); i < iend; ++i) {
            if (wordDict.find(s.substr(start, i-start+1)) != wordDict.end()) {
                if (unmatch.find(s.substr(i+1)) == unmatch.end()) {
                    if (wordBreak(s, wordDict, i+1, unmatch))
                        return true;
                    else
                        unmatch.insert(s.substr(i+1));
                } else
                    continue;
            }
        }
        return false;
    }

};

int main(void)
{
    string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    string array[] = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    //string s = "dogs";
    //string array[] = {"dog", "s", "gs"};
    unordered_set<string> wordDict(array, array+sizeof(array)/sizeof(int));
    cout << Solution().wordBreak(s, wordDict) << endl;
    return 0;
}
