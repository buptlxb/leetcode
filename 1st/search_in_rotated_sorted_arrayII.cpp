#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (nums[mid] == target) {
                return true;;
            } else if (nums[mid] < nums[right]) {
                if (nums[mid] < target && nums[right] >= target)
                    left = mid + 1;
                else
                    right = mid - 1;
            } else if (nums[mid] > nums[right]) {
                if (nums[left] <= target && nums[mid] > target)
                    right = mid - 1;
                else
                    left = mid + 1;
            } else {
                --right;
            }
        }
        return false;
    }
};

int main(void)
{
    //int array[] = {4, 5, 6, 6, 7, 0, 1, 2};
    int array[] = {3, 1, 1};
    vector<int> nums(array, array+sizeof(array)/sizeof(int));
    int target;
    while (cin >> target) {
        cout << Solution().search(nums, target) << endl;
    }
    return 0;
}
