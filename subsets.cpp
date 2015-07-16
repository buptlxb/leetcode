#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution {
public:
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
    vector<vector<int> > subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > ret;
        vector<int> tmp;
        ret.push_back(tmp);
        for (int k = 1; k < nums.size(); ++k) {
            combine(nums, 0, k, tmp, ret);
            tmp.clear();
        }
        ret.push_back(nums);
        return ret;
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
    int array[] = {1, 2, 3};
    vector<int> nums(array, array+sizeof(array)/sizeof(int));
    vector<vector<int> > ret = Solution().subsets(nums);
    for_each(ret.begin(), ret.end(), PrintVec());
    return 0;
}
