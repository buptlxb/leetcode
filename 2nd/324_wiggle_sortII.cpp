#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type sz_t;
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> tmp(nums);
        for (sz_t i = 0, len=nums.size(), k = (len+1)/2, j=len; i < len; ++i)
            nums[i] = i & 0x1? tmp[--j]:tmp[--k];
    }
};

int main(void)
{
    vector<int> nums{3, 2, 2, 3, 1};
    Solution s;
    s.wiggleSort(nums);
    for (auto x : nums)
        cout << x << " ";
    cout << endl;
    return 0;
}
