#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type sz_t;
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty())
            return 0;
        vector<int> length(nums.size(), 1);
        for (sz_t i = 0, iend = nums.size(); i < iend; ++i) {
            for (sz_t j = i+1; j < iend; ++j) {
                if (nums[i] < nums[j])
                    length[j] = max(length[j], length[i]+1);
            }
        }
        return *max_element(length.begin(), length.end());
    }
    int lengthOfLISII(vector<int>& nums) {
        if (nums.empty())
            return 0;
        vector<int> lis(1, nums.front());
        for (vector<int>::iterator i = nums.begin(), iend = nums.end(); i != iend; ++i) {
            if (*i > lis.back())
                lis.push_back(*i);
            else
                *lower_bound(lis.begin(), lis.end(), *i) = *i;
        }
        return lis.size();
    }
};

int main(void)
{
    vector<int> nums{10, 9, 2, 5, 3, 4}, ref{2, 3, 7, 101};
    Solution s;
    cout << s.lengthOfLIS(nums) << endl;
    cout << s.lengthOfLISII(nums) << endl;
    return 0;
}
