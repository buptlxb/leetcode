#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type sz_t;
    int missingNumber(vector<int>& nums) {
        int x = 0;
        for (sz_t i = 0, iend = nums.size(); i < iend; ++i)
            x ^= (i+1) ^ nums[i];
        return x;
    }
};

int main(void)
{
    Solution s;
    vector<int> nums{0, 1, 3};
    assert(s.missingNumber(nums) == 2);
    return 0;
}
