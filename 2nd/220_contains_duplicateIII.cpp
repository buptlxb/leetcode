#include <iostream>
#include <vector>
#include <map>

using namespace std;


class Solution {
public:
    typedef vector<int>::size_type sz_t;
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<int, sz_t> m;
        for (sz_t i = 0, j = 0, iend = nums.size(); i < iend; ++i) {
            if (j + k < i && m[nums[j]] == j) {
                m.erase(nums[j++]);
            }
            auto lb = m.lower_bound(nums[i] - t);
            if (lb != m.end() && lb->first - nums[i] <= t)
                return true;
            m[nums[i]] = i;
        }
        return false;
    }
};

int main(void)
{
    vector<int> nums{-3, 3};
    Solution().containsNearbyAlmostDuplicate(nums, 2, 4);
    return 0;
}
