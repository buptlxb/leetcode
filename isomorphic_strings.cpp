#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char hash1[256] = {0, };
        char hash2[256] = {0, };
        for (string::size_type i = 0, isize = s.size(); i < isize; ++i) {
            if (hash1[s[i]] && hash1[s[i]] != t[i] || hash2[t[i]] && hash2[t[i]] != s[i])
                return false;
            hash1[s[i]] = t[i];
            hash2[t[i]] = s[i];
        }
        return true;
    }
};

int main(void)
{
    cout << Solution().isIsomorphic("egg", "add") << endl;
    cout << Solution().isIsomorphic("foo", "bar") << endl;
    cout << Solution().isIsomorphic("ab", "aa") << endl;
    return 0;
}
