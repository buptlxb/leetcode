#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1, c2, n1, n2;
        c1 = c2 = 0;
        for (auto x : nums) {
            if (x == n1)
                ++c1;
            else if (x == n2)
                ++c2;
            else if (c1 == 0) {
                n1 = x;
                c1 = 1;
            } else if (c2 == 0) {
                n2 = x;
                c2 = 1;
            } else {
                --c1;
                --c2;
            }
        }
        c1 = c2 = 0;
        vector<int> ret;
        for (auto x : nums) {
            if (x == n1)
                ++c1;
            else if (x == n2)
                ++c2;
        }
        if (c1 > nums.size() / 3)
            ret.push_back(n1);
        if (c2 > nums.size() / 3)
            ret.push_back(n2);
        return ret;
    }
};

int main(void)
{
    vector<int> nums{1, 2, 2, 2, 4};
    Solution().majorityElement(nums);
    return 0;
}
