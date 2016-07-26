#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (target == 0)
            return 0;
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mem;
        mem[0] = 1;
        return combinationSum4(nums, target, mem);
    }
    int combinationSum4(vector<int> &nums, int target, unordered_map<int, int> &mem) {
        if (mem.find(target) != mem.end())
            return mem[target];
        int ret = 0;
        for (auto x : nums) {
            if (x > target)
                break;
            else
                ret += combinationSum4(nums, target-x, mem);
        }
        return mem[target] = ret;
    }
};

int main(void)
{
    vector<int> nums{4, 2, 1};
    cout << Solution().combinationSum4(nums, 32) << endl;
    return 0;
}
