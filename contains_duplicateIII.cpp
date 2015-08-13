#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type s_t;
    typedef map<int, s_t> Tree;
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        s_t j = 0;
        Tree tree;
        for (s_t i = 0, iend = nums.size(); i < iend; ++i) {
            if (i - j > k && tree[nums[j]] == j)
                tree.erase(nums[j++]);
            Tree::iterator found = tree.lower_bound(nums[i]-t);
            if (found != tree.end() && abs((double)found->first - nums[i]) <= t)
                return true;
            tree[nums[i]] = i;
        }
        return false;
    }
};

int main(void)
{
    int array[] = {4, 2};
    vector<int> nums(array, array+2);
    cout << Solution().containsNearbyAlmostDuplicate(nums, 2, 1) << endl;
    return 0;
}
