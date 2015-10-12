#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type sz_t;
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        vector<int> tmp;
        vector<vector<int> > ret;
        sort(nums.begin(), nums.end());
        subsetsWithDup(nums, 0, tmp, ret);
        return ret;
    }
    void subsetsWithDup(vector<int> &nums, sz_t start, vector<int> &tmp, vector<vector<int> > &ret) {
        if (start == nums.size()) {
            ret.push_back(tmp);
            return;
        }
        subsetsWithDup(nums, start+1, tmp, ret);
        while (start < nums.size() && nums[start] == nums[start+1])
            ++start;
        tmp.push_back(nums[start]);
        subsetsWithDup(nums, start+1, tmp, ret);
        tmp.pop_back();
    }
};

int main(void)
{
    return 0;
}
