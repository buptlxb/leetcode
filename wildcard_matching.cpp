#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution {
public:
    typedef string::size_type s_t;
    bool isMatch(string s, string p) {
        vector<bool> tmp(s.size()+1, false);
        vector<vector<bool> > dp(p.size()+1, tmp);
        dp[0][0] = true;
        for (s_t i = 1, iend = p.size(); i <= iend; ++i) {
            if (dp[i-1][0] && p[i-1] == '*')
                dp[i][0] = true;
            for (s_t j = 1, jend = s.size(); j <= jend; ++j) {
                if (p[i-1] == '*')
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                else if (p[i-1] == '?')
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = dp[i-1][j-1] && p[i-1] == s[j-1];
            }
        }
        return dp[p.size()][s.size()];
    }
};

int main(void)
{
    Solution s;
    cout << s.isMatch("a","aa") << endl;
    cout << s.isMatch("b","*?*?") << endl;
    cout << s.isMatch("aa","a") << endl;
    cout << s.isMatch("aa","aa") << endl;
    cout << s.isMatch("aaa","aa") << endl;
    cout << s.isMatch("aa", "*") << endl;
    cout << s.isMatch("aa", "a*") << endl;
    cout << s.isMatch("ab", "?*") << endl;
    cout << s.isMatch("aab", "c*a*b") << endl;
    cout << s.isMatch("aaaabaaaabbbbaabbbaabbaababbabbaaaababaaabbbbbbaabbbabababbaaabaabaaaaaabbaabbbbaababbababaabbbaababbbba", "*****b*aba***babaa*bbaba***a*aaba*b*aa**a*b**ba***a*a*") << endl;

    cout << s.isMatch("aaaaaaabababbababaaaabbbbbabababbbbbbaabbbbbbabbbabbbbaaaaaabababbabbaaabbbbababbbaaaaaaaababaaababababababbbbaabaabababbbbabbbbaabbaababbbaaabbabbbabaaabababaaaabaababaaaaabaaabbbabbaabbbbabbabbaaaaaaaa", "a*a***a*bbb*abb**babbba****ba*aa*a**a*aba*ba***b*a*ab**bb**b***b*b**a*aabbba*ab*a*******bba*a*a******") << endl;

    return 0;
}
