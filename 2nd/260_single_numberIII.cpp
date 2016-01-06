#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        assert(nums.size() > 1);
        if (nums.size() == 2)
            return nums;
        int res = accumulate(nums.begin(), nums.end(), 0, [](int a, int b){ return a ^ b; });
        unsigned mask = 1;
        while ((res & mask) == 0)
            mask <<= 1;
        vector<int> ret(2);
        for (auto x : nums) {
            if (x & mask)
                ret[0] ^= x;
            else
                ret[1] ^= x;
        }
        return ret;
    }
};

int main(void)
{
    Solution s;
    vector<int> nums{1, 2, 1, 3, 2, 5};
    vector<int> res{3, 5};
    vector<int> ret = s.singleNumber(nums);
    sort(ret.begin(), ret.end());
    assert(equal(res.begin(), res.end(), ret.begin()));
    return 0;
}
