#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int a{0}, b{0}, c{0};
        for (auto x : nums) {
            c = max(b, a + x);
            a = b;
            b = c;
        }
        return c;
    }
};

int main(void)
{
    return 0;
}
