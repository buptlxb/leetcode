#include <iostream>
#include <algorithm>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type sz_t;
    vector<int> productExceptSelf(vector<int>& nums) {
        assert(nums.size() > 1);
        vector<int> ret(nums.size(), 1);
        partial_sum(nums.begin(), nums.end()-1, ret.begin()+1, multiplies<int>());
        int partial = 1;
        for (sz_t i = nums.size()-1; i > 0; --i) {
            partial *= nums[i];
            ret[i-1] *= partial;
        }
        return ret;
    }
};

int main(void)
{
    Solution s;
    vector<int> nums{1, 2, 3, 4, 5};
    s.productExceptSelf(nums);
    return 0;
}
