#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type sz_t;
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> s;
        vector<int> ret;
        for (sz_t i = 0, j = 0, iend = nums.size(); i < iend; ++i) {
            if (j + k == i) {
                s.erase(s.find(nums[j++]));
            }
            s.insert(nums[i]);
            if (s.size() == k)
                ret.push_back(*s.rbegin());
        }
        return ret;
    }
};

int main(void)
{
    Solution s;
    vector<int> nums{1,3,-1,-3,5,3,6,7};
    vector<int> res{3,3,5,5,6,7};
    assert(equal(res.begin(), res.end(), s.maxSlidingWindow(nums, 3).begin()));
    return 0;
}
