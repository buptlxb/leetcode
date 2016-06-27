#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int>::size_type size = nums.size();
        vector<int>::size_type max = 0;
        for (vector<int>::size_type i = 0; i < size; ++i) {
            if (max < i)
                return false;
            if (max < i + nums[i])
                max = i + nums[i];
            if (max >= size-1)
                return true;
        }
        return false;
    }
};

int main(void)
{
    int array1[] = {2, 3, 1, 1, 4};
    int array2[] = {3, 2, 1, 0, 4};
    vector<int> nums(array2, array2+sizeof(array2)/sizeof(int));
    cout << Solution().canJump(nums) << endl;
    return 0;
}
