#include <iostream>
#include <vector>
#include <deque>
#include <iterator>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type s_t;
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        if (nums.empty())
            return ret;
        deque<int> dq;
        s_t i;
        for (i = 0; i < k; ++i) {
            while (!dq.empty() && nums[i] >= nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        for (s_t iend = nums.size(); i < iend; ++i) {
            ret.push_back(nums[dq.front()]);
            while (!dq.empty() && nums[i] >= nums[dq.back()])
                dq.pop_back();
            while (!dq.empty() && dq.front() <= i-k)
                dq.pop_front();
            dq.push_back(i);
        }
        ret.push_back(nums[dq.front()]);
        return ret;
    }
};

int main(void)
{
    int a[] = {1,3,-1,-3,5,3,6,7};
    vector<int> nums(a, a+sizeof(a)/sizeof(int));
    vector<int> ret = Solution().maxSlidingWindow(nums, 3);
    copy(ret.begin(), ret.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;
    return 0;
}
