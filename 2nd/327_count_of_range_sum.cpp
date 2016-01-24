#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class BinaryIndexedTree {
    vector<int> bit;
public:
    typedef vector<int>::size_type sz_t;
    BinaryIndexedTree(vector<int> &nums) : bit(nums.size()+1) {
        for (sz_t i = 0, iend = nums.size(); i < iend; ++i) {
            add(i+1, nums[i]);
        }
    }
    BinaryIndexedTree(sz_t n) : bit(n+1) { }
    void add(sz_t index, int delta) {
        for (; index < bit.size(); index += index & -index)
            bit[index] += delta;
    }
    int query(sz_t index) {
        int ret = 0;
        for (; index > 0; index -= index & -index)
            ret += bit[index];
        return ret;
    }
};

class Solution {
public:
    typedef vector<int>::size_type sz_t;
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int ret = 0;
        if (nums.empty())
            return ret;
        vector<long long> sums{lower-1, upper};
        long long total = 0;
        for (sz_t i = 0, iend = nums.size(); i < iend; ++i) {
            total += nums[i];
            sums.push_back(lower-1+total);
            sums.push_back(total);
            sums.push_back(upper+total);
        }
        vector<long long> usums(sums);
        sort(usums.begin(), usums.end());
        usums.erase(unique(usums.begin(), usums.end()), usums.end());
        map<long long, sz_t> hash;
        for (sz_t i = 0, iend = usums.size(); i < iend; ++i) {
            hash[usums[i]] = i+1;
        }
        BinaryIndexedTree bit(usums.size());
        for (sz_t i = nums.size(); i > 0; --i) {
            bit.add(hash[total], 1);
            total -= nums[i-1];
            ret += bit.query(hash[total+upper]) - bit.query(hash[total+lower-1]);
        }
        return ret;
    }
};

int main(void)
{
    vector<int> nums{-2, 5, -1};
    Solution s;
    cout << s.countRangeSum(nums, -2, 2) << endl;
    return 0;
}
