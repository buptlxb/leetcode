#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type sz_t;
    void moveZeroes(vector<int>& nums) {
        sz_t i = 0, j = 0, iend = nums.size();
        while (i < iend && nums[i])
            ++i;
        j = i;
        for (; i < iend; ++i) {
            if (nums[i]) {
                nums[j++] = nums[i];
            }
        }
        for (; j < iend; ++j)
            nums[j] = 0;
    }
    void moveZeroesII(vector<int> &nums) {
        fill(remove(nums.begin(), nums.end(), 0), nums.end(), 0);
    }
};

int main(void)
{
    return 0;
}
