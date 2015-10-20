#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type sz_t;
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        vector<int> tmp;
        vector<vector<int> > ret;
        sort(nums.begin(), nums.end());
        for (sz_t k = 0, kend = nums.size(); k < kend; ++k) {
            tmp.clear();
            subsetsWithDup(nums, 0, k, tmp, ret);
        }
        ret.push_back(nums);
        return ret;
    }
    void subsetsWithDup(vector<int> &nums, sz_t start, sz_t k, vector<int> &tmp, vector<vector<int> > &ret) {
        if (k == 0) {
            ret.push_back(tmp);
            return;
        }
        for (sz_t i = start, iend = nums.size(); i < iend; ++i) {
            if (i == start || nums[i] != nums[i-1]) {
                tmp.push_back(nums[i]);
                subsetsWithDup(nums, i+1, k-1, tmp, ret);
                tmp.pop_back();
            }
        }
    }
};

int main(void)
{
    return 0;
}
