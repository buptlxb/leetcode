#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type sz_t;
    vector<vector<int> > permute(vector<int>& nums) {
        vector<int> tmp;
        vector<vector<int> > ret;
        permute(nums, 0, tmp, ret);
        return ret;
    }
    void permute(vector<int> &nums, sz_t start, vector<int> &tmp, vector<vector<int> > &ret) {
        if (start == nums.size()) {
            ret.push_back(tmp);
            return;
        }
        for (sz_t i = start, iend = nums.size(); i < iend; ++i) {
            swap(nums[start], nums[i]);
            tmp.push_back(nums[start]);
            permute(nums, start+1, tmp, ret);
            tmp.pop_back();
            swap(nums[start], nums[i]);
        }
    }
};

int main(void)
{
    vector<int> nums(1, 1);
    Solution().permute(nums);
    return 0;
}
