#include <iostream>
#include <vector>
#include <limits>
#include <cassert>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type sz_t;
    int minSubArrayLen(int s, vector<int>& nums) {
        sz_t ret = numeric_limits<sz_t>::max();
        for (sz_t start = 0, sum = 0, i = 0, iend = nums.size(); i < iend; ++i) {
            sum += nums[i];
            while (sum >= s) {
                ret = min(ret, i-start+1);
                sum -= nums[start++];
            }
        }
        return ret == numeric_limits<sz_t>::max() ? 0 : ret;
    }
};

int main(void)
{
    Solution s;
    vector<int> vec{2,3,1,2,4,3};
    assert(2 == s.minSubArrayLen(7, vec));
    return 0;
}
