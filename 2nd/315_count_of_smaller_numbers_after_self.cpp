#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


class Solution {
public:
    typedef vector<int>::size_type sz_t;
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ret;
        if (nums.empty())
            return ret;
        vector<int> tmp(nums);
        sort(tmp.begin(), tmp.end());
        tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
        map<int, sz_t> m;
        for (sz_t i = 0, iend = tmp.size(); i < iend; ++i)
            m[tmp[i]] = i;
        const sz_t len = nums.size();
        ret.resize(len);
        vector<int> cnt(tmp.size());
        for (sz_t i = nums.size(); i > 0; --i) {
            ret[i-1] = cnt[m[nums[i-1]]];
            for (sz_t j = m[nums[i-1]] + 1; j < cnt.size(); ++j)
                ++cnt[j];
        }
        return ret;
    }
};

int main(void)
{
    vector<int> nums{5, 2, 6, 1};
    Solution s;
    vector<int> ret = s.countSmaller(nums);
    for (auto x : ret)
        cout << x << endl;
    return 0;
}
