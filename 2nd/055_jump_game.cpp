#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type sz_t;
    bool canJump(vector<int>& nums) {
        int cur = 0;
        for (sz_t i = 0, iend = nums.size(); i < iend; ++i) {
            if (cur < i)
                return false;
            cur = max(cur, i+nums[i]);
            if (cur >= iend)
                return true;
        }
        return false;
    }
};

int main(void)
{
    return 0;
}
