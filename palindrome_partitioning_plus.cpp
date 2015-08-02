#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cstdlib>

using namespace std;

class Solution {

public:
    typedef string::size_type s_t;
    int minCut(string s) {
        if (s.empty())
            return 0;
        vector<vector<bool> > palindrome(s.size(), vector<bool>(s.size(), false));
        vector<int> cut(s.size()+1, 0);
        for (s_t i = s.size(); i > 0; --i) {
            cut[i-1] = s.size();
            for (s_t j = i-1, jend = s.size(); j < jend; ++j) {
                if (s[i-1] == s[j] && (j-i+1 < 2 || palindrome[i][j-1])) {
                    palindrome[i-1][j] = true;
                    cut[i-1] = min(cut[i-1], cut[j+1]+1);
                }
            }
        }
        return cut[0] - 1;
    }
};

int main(void)
{
    cout << Solution().minCut("fifgbeajcacehiicccfecbfhhgfiiecdcjjffbghdidbhbdbfbfjccgbbdcjheccfbhafehieabbdfeigbiaggchaeghaijfbjhi") << endl;
    cout << Solution().minCut("aab") << endl;
    return 0;
}
