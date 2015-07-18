#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();
        vector<int>::size_type i = 2, j = 1;
        vector<int>::size_type iend = nums.size();
        int tmp = nums[1];
        for (i = 2; i < iend; ++i) {
            if (nums[i-2] != nums[i]) {
                nums[j++] = tmp;
                tmp = nums[i];
            }
        }
        nums[j++] = tmp;
        return j;
    }
};

int main(void)
{
    int array[] = {1,1,1,2,2,3};
    vector<int> nums(array, array+sizeof(array)/sizeof(int));
    cout << Solution().removeDuplicates(nums) << endl;
    return 0;
}
