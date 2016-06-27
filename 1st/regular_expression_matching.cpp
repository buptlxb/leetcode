#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    typedef string::size_type sz_t;
    bool isMatch(string s, string p) {
        return isMatchIter(s, 0, p, 0);
    }
    bool isMatchIter(const string &s, sz_t si, const string &p, sz_t pi) {
        if (pi == p.size())
            return si == s.size();
        if (pi == p.size()-1 || p[pi+1] != '*') {
            if (si == s.size() || s[si] != p[pi] && p[pi] != '.')
                return false;
            else
                return isMatchIter(s, si+1, p, pi+1);
        }
        while (si < s.size() && (p[pi] == '.' || p[pi] == s[si])) {
            if (isMatchIter(s, si, p, pi+2))
                return true;
            ++si;
        }
        return isMatchIter(s, si, p, pi+2);
    }
};

int main(void)
{
    string s = "aab";
    string p = "c*a*b*";
    cout << Solution().isMatch(s, p) << endl;
    return 0;
}
