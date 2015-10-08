#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int ret = nums.front();
        int cur = 0;
        for (auto x : nums) {
            cur += x;
            if (cur > ret)
                ret = cur;
            if (cur < 0)
                cur = 0;
        }
        return ret;
    }
};

int main(void)
{
    return 0;
}
