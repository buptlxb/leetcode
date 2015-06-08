#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret;
        ret.push_back(-1);
        ret.push_back(-1);
        if (nums.size() == 0)
            return ret;
        int left = 0;
        int right = nums.size()-1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        int l = left;
        right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if (l <= right) {
            ret[0] = l;
            ret[1] = right;
        }
        return ret;
    }
};

int main(void)
{
    int array[] = {5, 7, 7, 8, 8, 10};
    vector<int> nums(array, array + sizeof(array)/sizeof(int));
    int target;
    while (cin >> target) {
        vector<int> vec = Solution().searchRange(nums, target);
        cout << "[ ";
        for (vector<int>::iterator i = vec.begin(), iend = vec.end(); i != iend; ++i) {
            cout << *i << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}
