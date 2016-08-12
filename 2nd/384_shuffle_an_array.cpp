#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<int> nums;
public:
    Solution(vector<int> n) : nums(n) {
        srand(time(NULL));
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> ret(nums);
        for (int i = nums.size()-1; i > 0; --i) {
            swap(nums[i], nums[rand()%(i+1)]);
        }
        return ret;
    }
};

int main(void)
{
    return 0;
}
