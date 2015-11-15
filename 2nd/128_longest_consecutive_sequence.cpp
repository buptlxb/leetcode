#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    enum Direction {LEFT=-1, RIGHT=1};
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us;
        int ret = 0;
        for (auto x : nums)
            us.insert(x);
        for (auto x : nums)
            ret = max(ret, bound(us, x, LEFT) + bound(us, x+1, RIGHT));
        return ret;
    }
    int bound(unordered_set<int> &us, int x, Direction d) {
        int ret = 0;
        while (us.erase(x)) {
            x += d;
            ++ret;
        }
        return ret;
    }
};

int main(void)
{
    Solution s;
    int a[] = {100, 4, 200, 1, 3, 2};
    vector<int> nums(a, a+sizeof(a)/sizeof(int));
    assert(4 == s.longestConsecutive(nums));
    return 0;
}
