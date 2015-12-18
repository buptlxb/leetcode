#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;
        vector<char> m(128, -1);
        vector<char> n(m);
        for (string::size_type i = 0, iend = s.size(); i < iend; ++i) {
            if (m[s[i]] == -1 && n[t[i]] == -1) {
                m[s[i]] = t[i];
                n[t[i]] = s[i];
            } else if (m[s[i]] != t[i] || n[t[i]] != s[i]) {
                return false;
            }
        }
        return true;
    }
};

int main(void)
{
    Solution s;
    assert(s.isIsomorphic("add", "egg"));
    assert(!s.isIsomorphic("foo", "bar"));
    assert(s.isIsomorphic("paper", "title"));
    assert(!s.isIsomorphic("aa", "ab"));
    return 0;
}
