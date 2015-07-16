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
        combine(candidates, 0, k, tmp, ret);
        return ret;
    }
    void combine(const vector<int> &candidates, int start, int k, vector<int> &tmp, vector<vector<int> > &ret) {
        if (k == 0) {
            ret.push_back(tmp);
        } else {
            for (vector<int>::size_type i = start, iend = candidates.size(); i < iend; ++i) {
                tmp.push_back(candidates[i]);
                combine(candidates, i+1, k-1, tmp, ret);
                tmp.pop_back();
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
