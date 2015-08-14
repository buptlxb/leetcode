#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<int> tmp;
        vector<vector<int> > ret;
        combinationSum3(1, k, n, tmp, ret);
        return ret;
    }
    void combinationSum3(int start, int k, int n, vector<int> &tmp, vector<vector<int> > &ret) {
        if (k == 1) {
            if (n >= start && n < 10) {
                tmp.push_back(n);
                ret.push_back(tmp);
                tmp.pop_back();
            }
        } else if (n > start) {
            for (int i = start; i < 10; ++i) {
                tmp.push_back(i);
                combinationSum3(i+1, k-1, n-i, tmp, ret);
                tmp.pop_back();
            }
        }
    }
};

int main(void) {
    vector<vector<int> > ret = Solution().combinationSum3(1, 7);
    for (vector<vector<int> >::size_type i = 0, iend = ret.size(); i < iend; ++i) {
        copy(ret[i].begin(), ret[i].end(), ostream_iterator<int>(cout, ", "));
        cout << endl;
    }
    return 0;
}
