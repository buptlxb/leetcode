#include <iostream>
#include <vector>
#include <climits>
#include <cstdlib>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    typedef vector<int>::size_type size_type;
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ret = nums[0] + nums[1] + nums[2] - target;
        for (size_type i = 0; i < nums.size()-2; ++i) {
            int cur = twoSum(nums, i+1, target-nums[i]);
            if (abs(cur) < abs(ret))
                ret = cur;
        }
        return ret + target;
    }

    int twoSum(vector<int>& nums, size_type start, int target) {
        int sum = INT_MAX;
        size_type left = start;
        size_type right = nums.size()-1;
        while (left < right) {
            int diff = nums[left] + nums[right] - target;
            if (diff == 0)
                return 0;
            if (abs(diff) < abs(sum))
                sum = diff;
            if (diff < 0)
                ++left;
            else
                --right;
        }
        return sum;
    }
};

int main(void)
{
    int array[] = {-1, 2, 1, -4};
    vector<int> nums(array, array+sizeof(array)/sizeof(int));
    cout << Solution().threeSumClosest(nums, 1) << endl;
    return 0;
}
