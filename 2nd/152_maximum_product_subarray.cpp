#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty())
            return 0;
        vector<int> gmax(2, nums.front()), lmax(gmax), lmin(lmax);
        int idx = 0;
        for (auto i = nums.begin()+1, iend = nums.end(); i != iend; ++i) {
            lmax[idx] = trimax(lmax[1-idx] * *i, lmin[1-idx] * *i, *i);
            lmin[idx] = trimin(lmax[1-idx] * *i, lmin[1-idx] * *i, *i);
            gmax[idx] = max(gmax[1-idx], lmax[idx]);
            idx = 1 - idx;
        }
        return gmax[1-idx];
    }
    int trimin(int a, int b, int c) {
        return min(a, min(b, c));
    }
    int trimax(int a, int b, int c) {
        return max(a, max(b, c));
    }
};

int main(void)
{
    return 0;
}
