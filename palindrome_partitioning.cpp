#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {

public:
    typedef string::size_type s_t;
    vector<vector<string> > partition(string s) {
        vector<vector<string> > ret;
        if (s.empty())
            return ret;
        vector<string> tmp;
        partition(s, 0, tmp, ret);
        return ret;
    }
    void partition(const string &s, s_t start, vector<string> &tmp, vector<vector<string> > &ret) {
        if (start == s.size()) {
            ret.push_back(tmp);
            return;
        }
        for (s_t i = start, iend = s.size(); i < iend; ++i) {
            if (isPalindrome(s, start, i+1)) {
                tmp.push_back(s.substr(start, i-start+1));
                partition(s, i+1, tmp, ret);
                tmp.pop_back();
            }
        }
    }
    bool isPalindrome(const string &s, s_t start, s_t end) {
        if (start == end || start+1 == end)
            return true;
        if (s[start] != s[end-1])
            return false;
        return isPalindrome(s, start+1, end-1);
    }
};

int main(void)
{
    vector<vector<string> > ret = Solution().partition("aab");
    for (vector<vector<string> >::iterator i = ret.begin(), iend = ret.end(); i != iend; ++i) {
        copy(i->begin(), i->end(), ostream_iterator<string>(cout, ", "));
        cout << endl;
    }
    return 0;
}
