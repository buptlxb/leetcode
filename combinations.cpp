#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ret;
        vector<int> tmp, candidates;
        candidates.reserve(n);
        for (int i = 1; i <= n; ++i)
            candidates.push_back(i);
        combine(candidates, k, tmp, ret);
        return ret;
    }
    void combine(vector<int> candidates, int k, vector<int> &tmp, vector<vector<int> > &ret) {
        if (k == 0) {
            ret.push_back(tmp);
        } else {
            for (vector<int>::iterator i = candidates.begin(), iend = candidates.end(); i < iend; ++i) {
                if (tmp.empty() || *i > tmp.back()) {
                    tmp.push_back(*i);
                    vector<int> tc;
                    copy(candidates.begin(), i, back_inserter(tc));
                    copy(i, candidates.end(), back_inserter(tc));
                    combine(tc, k-1, tmp, ret);
                    tmp.pop_back();
                }
            }
        }
    }
};

ostream & operator<< (ostream &os, vector<int> vec) {
    copy(vec.begin(), vec.end(), ostream_iterator<int>(os, ", "));
    return os;
}

struct PrintVec {
    void operator() (vector<int> vec) { cout << vec << endl; }
};

int main(void)
{
    vector<vector<int> > ret = Solution().combine(4, 2);
    for_each(ret.begin(), ret.end(), PrintVec());
    return 0;
}
