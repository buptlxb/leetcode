#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type sz_t;
    int minPatches(vector<int>& nums, int n) {
        sz_t miss = 1, idx = 0, ret = 0;
        while (miss <= n) {
            if (idx < nums.size() && nums[idx] <= miss)
                miss += nums[idx++];
            else {
                miss += miss;
                ++ret;
            }
        }
        return ret;
    }
};

int main(void)
{
    vector<int> nums{1, 5, 10};
    Solution s;
    cout << s.minPatches(nums, 20) << endl;
    return 0;
}
