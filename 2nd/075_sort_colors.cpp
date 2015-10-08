#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroEnd = -1, twoStart = nums.size();
        for (int i = 0; i < twoStart; ) {
            if (nums[i] == 0 && i != ++zeroEnd)
                swap(nums[i], nums[zeroEnd]);
            else if (nums[i] == 2 && i != --twoStart)
                swap(nums[i], nums[twoStart]);
            else
                ++i;
        }
    }
};

int main(void)
{
    return 0;
}
