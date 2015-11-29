#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ret = nums.front(), votes = 0;
        for (auto x : nums) {
            x == ret ? ++votes : --votes;
            if (votes < 0) {
                ret = x;
                votes = 1;
            }
        }
        return ret;
    }
};

int main(void)
{
    return 0;
}
