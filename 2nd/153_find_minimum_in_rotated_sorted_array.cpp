#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        return findMin(nums, 0, nums.size()-1);
    }
    int findMin(vector<int> &nums, int left, int right) {
        if (left == right || nums[left] < nums[right])
            return nums[left];
        int mid = left + (right-left) / 2;
        if (nums[mid] > nums[right])
            return findMin(nums, mid+1, right);
        return findMin(nums, left, mid);
    }
};

int main(void)
{
    return 0;
}
