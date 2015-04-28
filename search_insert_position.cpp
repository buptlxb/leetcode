#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        vector<int>::size_type left = 0, right = nums.size()-1;
        while (left < right) {
            vector<int>::size_type mid = left + (right-left)/2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target) {
                left = mid+1;
            } else {
                if (mid > 0)
                    right = mid-1;
                else
                    break;
            }
        }
        return nums[left] >= target ? left : left+1;
    }
};

int main(void)
{
    int array[] = {1, 3, 5, 6};
    Solution s;
    vector<int> tmp(array, array+sizeof(array)/sizeof(array[0]));
    cout << s.searchInsert(tmp, 5) << endl;
    cout << s.searchInsert(tmp, 2) << endl;
    cout << s.searchInsert(tmp, 7) << endl;
    cout << s.searchInsert(tmp, 0) << endl;

    int array1[] = {2, 5};
    Solution s1;
    vector<int> tmp1(array, array+sizeof(array)/sizeof(array[0]));
    cout << s1.searchInsert(tmp1, 1) << endl;

    return 0;
}
