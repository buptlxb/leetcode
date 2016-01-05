#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type sz_t;
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, sz_t> m;
        for (sz_t i = 0, iend = nums.size(); i < iend; ++i) {
            if (m.find(nums[i]) != m.end() && i - m[nums[i]] <= k)
                return true;
            m[nums[i]] = i;
        }
        return false;
    }
};

int main(void)
{
    return 0;
}
