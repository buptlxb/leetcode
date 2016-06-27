#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type s_t;
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > ret;
        vector<int> tmp;
        ret.push_back(tmp);
        sort(nums.begin(), nums.end());
        for (s_t k = 1; k < nums.size(); ++k) {
            vector<vector<int> > tmp = combination(nums, k);
            ret.insert(ret.end(), tmp.begin(), tmp.end());
        }
        ret.push_back(nums);
        return ret;
    }
    vector<vector<int> > combination(const vector<int> &nums, s_t k) {
        vector<vector<int> > ret;
        vector<int> tmp;
        combination(nums, 0, k, tmp, ret);
        return ret;
    }

    void combination(const vector<int> &nums, s_t i, s_t k, vector<int> &tmp, vector<vector<int> > &ret) {
        if (tmp.size() == k) {
            ret.push_back(tmp);
        } else {
            s_t start = i;
            while (i < nums.size()) {
                if (i == start || nums[i] != nums[i-1]) {
                    tmp.push_back(nums[i]);
                    combination(nums, i+1, k, tmp, ret);
                    tmp.pop_back();
                }
                i++;
            }
        }
    }
};

ostream & operator<< (ostream &os, vector<vector<int> > vec) {
    for (vector<vector<int> >::iterator i = vec.begin(), iend = vec.end(); i != iend; ++i) {
        copy(i->begin(), i->end(), ostream_iterator<int>(os, ", "));
        os << endl;
    }
    return os;
}

int main(void)
{
    int array[] = {1, 2, 2};
    vector<int> nums(array, array+sizeof(array)/sizeof(int));
    vector<vector<int> > ret = Solution().subsetsWithDup(nums);
    cout << ret << endl;
    return 0;
}
