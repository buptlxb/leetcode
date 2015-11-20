#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    typedef vector<string>::size_type sz_t;
    vector<vector<string> > partition(string s) {
        vector<vector<string> > ret;
        const sz_t len = s.size();
        if (len < 2) {
            ret.push_back(vector<string>(1, s));
            return ret;
        }
        vector<vector<bool> > dp(len, vector<bool>(len, false));
        for (sz_t i = 0; i < len; ++i) {
            dp[i][i] = true;
        }
        for (sz_t i = 1; i < len; ++i) {
            for (sz_t j = 0; i+j < len; ++j) {
                dp[j][i+j] = i == 1 ? s[j] == s[i+j] : s[j] == s[i+j] && dp[j+1][i+j-1];
            }
        }
        vector<string> tmp;
        partition(dp, s, tmp, ret, 0);
        return ret;
    }
    void partition(vector<vector<bool> > &dp, string &s, vector<string> &tmp, vector<vector<string> > &ret, sz_t idx) {
        if (idx == s.size()) {
            ret.push_back(tmp);
        } else {
            for (sz_t i = s.size(); i > idx; --i) {
                if (dp[idx][i-1]) {
                    tmp.push_back(s.substr(idx, i-idx));
                    partition(dp, s, tmp, ret, i);
                    tmp.pop_back();
                }
            }
        }
    }
};

int main(void)
{
    Solution s;
    vector<vector<string> > ret = s.partition("a");
    for (auto x : ret) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}
