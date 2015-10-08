#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        const int len = nums.size();
        vector<bool> positives(len, false);
        for (auto x : nums) {
            if (x > len || x <= 0)
                continue;
            positives[x-1] = true;
        }
        for (vector<int>::size_type i = 0; i < len; ++i) {
            if (positives[i])
                continue;
            return i+1;
        }
        return len+1;
    }
};

int main(void)
{
    return 0;
}
