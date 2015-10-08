#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while (left <= right) {
            int mid = left + (right-left) / 2;
            if (nums[mid] == target)
                return true;
            else if (nums[mid] > nums[right]) {
                if (nums[mid] > target && target >= nums[left])
                    right = mid - 1;
                else
                    left = mid+1;
            } else if (nums[mid] < nums[left]) {
                if (nums[mid] < target && target <= nums[right])
                    left = mid+1;
                else
                    right = mid-1;
            } else if (nums[mid] == nums[right]) {
                --right;
            } else if (nums[mid] == nums[left]) {
                ++left;
            }
        }
        return false;
    }
};

int main(void)
{
    return 0;
}
