#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret(2, 0);
        map<int, vector<int>::size_type> dict;
        for (vector<int>::size_type i = 0, iend = nums.size(); i < iend; ++i) {
            if (dict[target-nums[i]]) {
                ret[0] = dict[target-nums[i]];
                ret[1] = i+1;
            } else {
                dict[nums[i]] = i + 1;
            }
        }
        return ret;
    }
};

int main(void)
{
    int a[] = {2, 7, 11, 15};
    int target = 9;
    vector<int> nums(a, a+sizeof(a)/sizeof(a[0]));
    vector<int> ret = Solution().twoSum(nums, target);
    cout << ret[0] << " " << ret[1] << endl;
    return 0;
}
