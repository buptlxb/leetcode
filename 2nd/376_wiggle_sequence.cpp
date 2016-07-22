#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();
        int ret = 1;
        int i = 1, iend = nums.size();
        while (i < iend && nums[i] == nums[i-1])
            ++i;
        if (i == iend)
            return ret;
        ret = 2;
        bool direct = nums[i-1] < nums[i];
        for (i = i+1; i < iend; ++i) {
            if (direct && nums[i-1] > nums[i] || !direct && nums[i-1] < nums[i]) {
                ++ret;
                direct = !direct;
            }
        }
        return ret;
    }
};

int main(void)
{
    Solution s;
    vector<int> nums1{1,7,4,9,2,5}, nums2{1,17,5,10,13,15,10,5,16,8}, nums3{1,2,3,4,5,6,7,8,9}, nums4{0, 0};
    cout << s.wiggleMaxLength(nums1) << endl;
    cout << s.wiggleMaxLength(nums2) << endl;
    cout << s.wiggleMaxLength(nums3) << endl;
    cout << s.wiggleMaxLength(nums4) << endl;
    return 0;
}
