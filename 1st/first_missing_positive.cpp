#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (vector<int>::size_type i = 0, iend = nums.size(); i < iend; ++i) {
            if (nums[i] > iend || nums[i] <= 0) {
                nums[i] = -1;
            } else if (nums[i] != i+1 && nums[i] != nums[nums[i]-1]) {
                swap(nums[i], nums[nums[i]-1]);
                --i;
            }
        }
        for (vector<int>::size_type i = 0, iend = nums.size(); i < iend; ++i) {
            if (nums[i] != i+1)
                return i+1;
        }
        return nums.size()+1;
    }
};

int main(void)
{
    int array[] = {1, 1};
    vector<int> nums(array, array+sizeof(array)/sizeof(int));
    cout << Solution().firstMissingPositive(nums) << endl;
    return 0;
}
