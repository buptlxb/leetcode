#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type sz_t;
    typedef vector<int>::const_iterator CI;
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ret;
        for (sz_t i = max<int>(0, k - nums2.size()), iend = min<sz_t>(k, nums1.size()) + 1; i < iend; ++i) {
            vector<int> cur = merge(maxNumber(nums1, i), maxNumber(nums2, k-i));
            if (cur > ret)
                ret.swap(cur);
        }
        return ret;
    }
    vector<int> maxNumber(vector<int> &nums, int k) {
        vector<int> ret;
        ret.reserve(k);
        for (sz_t i = 0, iend = nums.size(); i < iend; ++i) {
            while (!ret.empty() && ret.size() + iend - i > k && ret.back() < nums[i])
                ret.pop_back();
            if (ret.size() < k)
                ret.push_back(nums[i]);
        }
        return ret;
    }
    vector<int> merge(const vector<int> &nums1, const vector<int> &nums2) {
        vector<int> ret;
        ret.reserve(nums1.size() + nums2.size());
        CI i = nums1.begin(), j = nums2.begin();
        CI iend = nums1.end(), jend = nums2.end();
        while (i != iend && j != jend) {
            ret.push_back(greater(i, iend, j, jend) ? *i++ : *j++);
        }
        copy(i, iend, copy(j, jend, back_inserter(ret)));
        return ret;
    }
    bool greater(CI first1, CI last1, CI first2, CI last2) {
        while (first1 != last1 && first2 != last2) {
            if (*first1 > *first2)
                return true;
            if (*first1 < *first2)
                return false;
            ++first1;
            ++first2;
        }
        return first1 != last1;
    }
};

int main(void)
{
    vector<int> nums1{3, 4, 6, 5};
    vector<int> nums2{9, 1, 2, 5, 8, 3};
    Solution s;
    vector<int> ret  = s.maxNumber(nums1, nums2, 5);
    for (auto x : ret)
        cout << x << " ";
    cout << endl;
    return 0;
}
