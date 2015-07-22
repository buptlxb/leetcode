#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution {
public:
    typedef string::size_type s_t;
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.empty())
            return s2 == s3;
        if (s2.empty())
            return s1 == s3;
        if (s2.size() + s1.size() != s3.size())
            return false;
        vector<int> tmp(s2.size()+1, 0);
        vector<vector<int> > a(s1.size()+1, tmp);
        a[0][0] = 1;
        for (s_t i = 0, iend = s1.size(); i < iend; ++i) {
            a[i+1][0] = a[i][0] && s1[i] == s3[i];
        }
        for (s_t j = 0, jend = s2.size(); j < jend; ++j) {
            a[0][j+1] = a[0][j] && s2[j] == s3[j];
        }

        for (s_t i = 0, iend = s1.size(); i < iend; ++i) {
            for (s_t j = 0, jend = s2.size(); j < jend; ++j) {
                a[i+1][j+1] = a[i][j+1] && s1[i] == s3[i+j+1] || a[i+1][j] && s2[j] == s3[i+j+1];
            }
        }
        for (vector<vector<int> >::size_type i = 0; i < a.size(); ++i) {
            copy(a[i].begin(), a[i].end(), ostream_iterator<int>(cout, ", "));
            cout << endl;
        }
        return a[s1.size()][s2.size()];
    }
    bool isInterleave(string &s1, string &s2, string &s3, s_t i, s_t j, s_t k) {
        if (i == s1.size())
            return s2.substr(j) == s3.substr(k);
        if (j == s2.size())
            return s1.substr(i) == s3.substr(k);
        if (k == s3.size())
            return i == s1.size() && j == s2.size();
        if (s1[i] == s3[k] && s2[j] == s3[k])
            return isInterleave(s1, s2, s3, i+1, j, k+1) || isInterleave(s1, s2, s3, i, j+1, k+1);
        if (s1[i] == s3[k])
            return isInterleave(s1, s2, s3, i+1, j, k+1);
        if (s2[j] == s3[k])
            return isInterleave(s1, s2, s3, i, j+1, k+1);
        return false;
    }
};

int main(void)
{
    cout << Solution().isInterleave("aabcc", "dbbca", "aadbbbaccc") << endl;
    return 0;
}
