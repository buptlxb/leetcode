#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type s_t;
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.begin()+k-1, nums.end(), greater<int>());
        return nums[k-1];
        //return findKthLargest(nums, 0, nums.size()-1, k);
    }
    int findKthLargest(vector<int> &nums, s_t left, s_t right, int k) {
        int pivot = nums[left];
        s_t i = left;
        s_t j = right;
        while (i < j) {
            while (i < j && pivot < nums[j])
                --j;
            if (i < j)
                nums[i++] = nums[j];
            while (i < j && pivot > nums[i])
                ++i;
            if (i < j)
                nums[j--] = nums[i];
        }
        nums[i] = pivot;
        copy(nums.begin()+left, nums.begin()+right+1, ostream_iterator<int>(cout, ", "));
        cout << endl;
        if (right-i == k-1)
            return pivot;
        else if (right-i < k-1) {
            return findKthLargest(nums, left, i-1, k-(right-i+1));
        } else
            return findKthLargest(nums, i+1, right, k);
    }
};

int main(void)
{
    int array[] = {3,2,1,5,6,4};
    vector<int> nums(array, array+sizeof(array)/sizeof(int));
    cout << Solution().findKthLargest(nums, 2) << endl;
    return 0;
}
