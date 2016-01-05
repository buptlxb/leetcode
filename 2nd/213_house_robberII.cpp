#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums.front();
        return max(rob(nums.begin(), nums.end()-1), rob(nums.begin()+1, nums.end()));
    }
    int rob(vector<int>::iterator first, vector<int>::iterator last) {
        int a, b, c;
        a = b = c = 0;
        for (; first < last; ++first) {
            a = max(c + *first, b);
            c = b;
            b = a;
        }
        return a;
    }
};

int main(void)
{
    return 0;
}
