#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution {
public:
    typedef vector<int>::size_type sz_t;
    int maxSubArray(vector<int>& nums) {
        int max = nums[0];
        int cur = max > 0 ? max : 0;
        for (vector<int>::size_type i = 1, stop = nums.size(); i < stop; ++i) {
            int tmp = nums[i] + cur;
            max = tmp > max ? tmp : max;
            cur = tmp > 0 ? tmp : 0;
        }
        return max;
    }
};


int main(void)
{
    int array[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> vec(array, array+sizeof(array)/sizeof(int));
    cout << Solution().maxSubArray(vec) << endl;
    return 0;
}
