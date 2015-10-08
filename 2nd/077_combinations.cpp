#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<int> tmp;
        vector<vector<int> > ret;
        combine(1, n, k, tmp, ret);
        return ret;
    }
    void combine(int start, int n, int k, vector<int> &tmp, vector<vector<int> > &ret) {
        if (k == 0) {
            ret.push_back(tmp);
            return;
        }
        for (int i = start, iend = n-k+1; i <= iend; ++i) {
            tmp.push_back(i);
            combine(i+1, n, k-1, tmp, ret);
            tmp.pop_back();
        }
    }
};

int main(void)
{
    vector<vector<int> > ret = Solution().combine(4, 2);
    for (int i = 0; i < ret.size(); ++i) {
        for (int j = 0; j < ret[i].size(); ++j) {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
