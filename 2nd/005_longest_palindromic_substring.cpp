#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty())
            return string();
        string::size_type left(0), right(0);
        vector<vector<bool> > dp(s.size(), vector<bool>(s.size(), false));
        for (string::size_type i = 0, iend = s.size(); i < iend; ++i) {
            dp[i][i] = true;
        }
        for (string::size_type i = s.size(); i > 0; --i) {
            for (string::size_type j = i-1, jend = s.size(); j < jend; ++j) {
                if (i-1 == j)
                    dp[i-1][j] = true;
                else if (i==j && s[i-1] == s[j])
                    dp[i-1][j] = true;
                else if (dp[i][j-1] && s[i-1] == s[j])
                    dp[i-1][j] = true;
                if (dp[i-1][j] && j-i+1 > right-left) {
                    right = j;
                    left = i-1;
                }
            }
        }
        for (string::size_type i = 0, iend = s.size(); i < iend; ++i) {
            for (string::size_type j = 0, jend = iend; j < jend; ++j) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return s.substr(left, right-left+1);
    }
};


int main(void)
{
    cout << Solution().longestPalindrome("abacabb") << endl;
    return 0;
}
