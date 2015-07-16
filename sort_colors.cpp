#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution {
    public:
        void sortColors(vector<int>& nums) {
            vector<int>::size_type cur_swap(nums.size()),  last_swap(nums.size());
            while (true) {
                for (vector<int>::size_type j = 1, jend = last_swap; j < jend; ++j) {
                    if (nums[j] < nums[j-1]) {
                        swap(nums[j], nums[j-1]);
                        cur_swap = j;
                    }
                }
                if (last_swap == cur_swap)
                    break;
                last_swap = cur_swap;
            }
        }
};

int main(void)
{
    int array[] = {1, 2, 2, 1, 0, 1, 0, 2};
    vector<int> nums(array, array+sizeof(array)/sizeof(int));
    Solution().sortColors(nums);
    copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;
    return 0;
}
