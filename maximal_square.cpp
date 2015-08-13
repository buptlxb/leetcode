#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type s_t;
    int maximalSquare(vector<vector<char> >& matrix) {
        int mk = 0;
        if (matrix.empty())
            return mk;
        vector<int> tmp(matrix.front().size(), 0);
        vector<vector<int> > dp(matrix.size(), tmp);
        for (s_t i = 0, iend = matrix.size(); i < iend; ++i) {
            for (s_t j = 0, jend = matrix[i].size(); j < jend; ++j) {
                if (matrix[i][j] == '1')
                    dp[i][j] = mk = 1;
            }
        }
        for (s_t i = 1, iend = matrix.size(); i < iend; ++i) {
            for (s_t j = 1, jend = matrix[i].size(); j < jend; ++j) {
                if (matrix[i][j] == '1')
                    dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]) + 1;
                if (dp[i][j] > mk)
                    mk = dp[i][j];
            }
        }
        return mk*mk;
    }
};

int main(void)
{
    //char a1[] = {'1', '0', '1', '0', '0'};
    //char a2[] = {'1', '0', '1', '1', '1'};
    //char a3[] = {'1', '1', '1', '1', '1'};
    //char a4[] = {'1', '0', '0', '1', '0'};
    //vector<char> v1(a1, a1+sizeof(a1)/sizeof(char));
    //vector<char> v2(a2, a2+sizeof(a2)/sizeof(char));
    //vector<char> v3(a3, a3+sizeof(a3)/sizeof(char));
    //vector<char> v4(a4, a4+sizeof(a4)/sizeof(char));
    //vector<vector<char> > matrix;
    //matrix.push_back(v1);
    //matrix.push_back(v2);
    //matrix.push_back(v3);
    //matrix.push_back(v4);
    char a1[] = {'1', '1'};
    char a2[] = {'1', '1'};
    vector<char> v1(a1, a1+sizeof(a1)/sizeof(char));
    vector<char> v2(a2, a2+sizeof(a2)/sizeof(char));
    vector<vector<char> > matrix;
    matrix.push_back(v1);
    matrix.push_back(v2);
    cout << Solution().maximalSquare(matrix) << endl;
    return 0;
}
