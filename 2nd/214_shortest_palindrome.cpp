#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    typedef string::size_type sz_t;
    string shortestPalindrome(string s) {
        if (s.size() < 2)
            return s;
        return string(s.rbegin(), s.rbegin()+s.size()-getLongestCommon(s)) + s;
    }
    sz_t getLongestCommon(string s) {
        string rev(s.rbegin(), s.rend());
        ostringstream os;
        os << s << '#' << rev;
        string t = os.str();
        vector<sz_t> com(t.size(), 0);
        for (sz_t i = 1, iend = t.size(); i < iend; ++i) {
            sz_t j = com[i-1];
            while (j > 0 && t[i] != t[j])
                j = com[j-1];
            com[i] = j ? j+1 : (t[i] == t[0] ? 1 : 0);
        }
        return com.back();
    }
};

int main(void)
{
    return 0;
}
