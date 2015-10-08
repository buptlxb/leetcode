#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret(2, -1);
        if (nums.empty())
            return ret;
        const int len = nums.size();
        int mid = binSearch(nums, 0, len-1, target);
        if (mid == -1)
            return ret;
        int left = mid, right = mid;
        while (mid != -1) {
            left = mid;
            mid = binSearch(nums, 0, left-1, target);
        }
        mid = right;
        while (mid != -1) {
            right = mid;
            mid = binSearch(nums, right+1, len-1, target);
        }
        ret[0] = left;
        ret[1] = right;
        return ret;
    }
    int binSearch(vector<int> &nums, int left, int right, int target) {
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                right = mid-1;
            else
                left = mid+1;
        }
        return -1;
    }
};

int main(void)
{
    int a[] = {5, 7, 7, 8, 8, 10};
    vector<int> nums(a, a+sizeof(a)/sizeof(int));
    vector<int> ret = Solution().searchRange(nums, 8);
    cout << ret[0] << ret[1] << endl;
    return 0;
}
