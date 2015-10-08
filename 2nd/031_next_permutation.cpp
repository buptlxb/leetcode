#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type sz_t;
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2)
            return;
        sz_t a = 0;
        const sz_t len = nums.size();
        for (sz_t i = 0; i < len-1; ++i)
            if (nums[i] < nums[i+1])
                a = i;
        if (nums[a] < nums[a+1]) {
            sz_t b = a+1;
            for (sz_t k = b+1; k < len; ++k) {
                if (nums[k] > nums[a] && nums[k] < nums[b])
                    b = k;
            }   
            swap(nums[a], nums[b]);
            sort(nums.begin()+a+1, nums.end());
        } else {
            sort(nums.begin(), nums.end());
        }
    }   
};

int main(void)
{
    int a[] = {3, 2, 1};
    vector<int> nums(a, a+3);
    Solution().nextPermutation(nums);
    for (auto n : nums)
        cout << n << endl;
    return 0;
}
