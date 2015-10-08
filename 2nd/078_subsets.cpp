#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type sz_t;
    vector<vector<int> > subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> tmp;
        vector<vector<int> > ret;
        subsets(nums, 0, tmp, ret);
        return ret;
    }
    void subsets(vector<int> &nums, sz_t start, vector<int> &tmp, vector<vector<int> > &ret) {
        if (start == nums.size()) {
            ret.push_back(tmp);
            return;
        }
        subsets(nums, start+1, tmp, ret);
        tmp.push_back(nums[start]);
        subsets(nums, start+1, tmp, ret);
        tmp.pop_back();
    }
};

int main(void)
{
    return 0;
}
