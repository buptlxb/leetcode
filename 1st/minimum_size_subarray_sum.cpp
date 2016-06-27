#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type s_t;
    int minSubArrayLen(int s, vector<int>& nums) {
        s_t ret = 0;
        if (accumulate(nums.begin(), nums.end(), 0) < s)
            return ret;
        ret = nums.size();
        s_t cur = 0;
        s_t start = 0;
        for (s_t i = 0, iend = nums.size(); i < iend; ++i) {
            cur += nums[i];
            if (cur >= s) {
                while (cur-nums[start] >= s) {
                    cur -= nums[start++];
                }
                ret = min(ret, i-start+1);
            }
        }
        return ret;
    }
};

int main(void)
{
    int a[] = {2,3,1,2,4,3};
    vector<int> nums(a, a+sizeof(a)/sizeof(int));
    cout << Solution().minSubArrayLen(7, nums) << endl;
    return 0;
}
