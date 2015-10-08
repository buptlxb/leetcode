#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        const int len = nums.size();
        if (len < 3)
            return len;
        int ret = 1;
        int cur = nums[0];
        int count = 1;
        for (int i = 1, iend = nums.size(); i < iend; ++i) {
            if (nums[i] == cur) {
                ++count;
                if (count <= 2)
                    nums[ret++] = nums[i];
            } else {
                nums[ret++] = nums[i];
                cur = nums[i];
                count = 1;
            }
        }
        return ret;
    }
};

int main(void)
{
    int a[] = {1,1,1,2,2,3};
    vector<int> nums(a, a+sizeof(a)/sizeof(int));
    Solution s;
    assert(5 == s.removeDuplicates(nums));
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
