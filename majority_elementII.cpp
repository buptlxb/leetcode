#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type s_t;
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ret;
        s_t c1(0), c2(0);
        int n1(0), n2(0);
        for (s_t i = 0, iend = nums.size(); i < iend; ++i) {
            if (nums[i] == n1)
                ++c1;
            else if (nums[i] == n2)
                ++c2;
            else if (c1 == 0) {
                c1 = 1;
                n1 = nums[i];
            } else if (c2 == 0) {
                c2 = 1;
                n2 = nums[i];
            } else {
                --c1;
                --c2;
            }
        }
        c1 = 0;
        c2 = 0;
        for (s_t i = 0, iend = nums.size(); i < iend; ++i) {
            if (nums[i] == n1)
                ++c1;
            else if (nums[i] == n2)
                ++c2;
        }
        if (c1 > nums.size()/3)
            ret.push_back(n1);
        if (c2 > nums.size()/3)
            ret.push_back(n2);
        return ret;
    }
};

int main(void)
{
    int a[] = {1, 2, 3, 3, 2};
    vector<int> nums(a, a+sizeof(a)/sizeof(int));
    vector<int> ret = Solution().majorityElement(nums);
    cout << ret[0] << ret[1] << endl;
    return 0;
}
