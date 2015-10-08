#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int ret = 0;
        if (nums.size() < 2)
            return ret;
        int a = 0;
        int b = 0;
        for (vector<int>::size_type i = 0, iend = nums.size(); i < iend; ++i) {
            if (b < i) {
                ++ret;
                b = a;
            }
            a = max(a, (int)i+nums[i]);
            if (b+1 >= iend)
                return ret;
        }
        return ret;
    }
};

int main(void)
{
    return 0;
}
