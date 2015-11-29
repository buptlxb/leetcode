#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return findPeakElement(nums, 0, nums.size()-1);
    }
    int findPeakElement(vector<int> &nums, int left, int right) {
        if (left == right)
            return nums[left];
        int mid = left + (right - left) / 2;
        if (mid == right || nums[mid] > nums[mid+1])
            return findPeakElement(nums, left, mid);
        return findPeakElement(nums, mid+1, right);
    }
};

int main(void)
{
    return 0;
}
