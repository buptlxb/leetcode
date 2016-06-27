#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type s_t;
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2)
            return 0;
        int a = *min_element(nums.begin(), nums.end());
        int b = *max_element(nums.begin(), nums.end());
        int len = (b - a) / nums.size() + 1;
        vector<vector<int> > buckets((b-a)/len + 1);
        for (s_t i = 0, iend = nums.size(); i < iend; ++i) {
            s_t index = (nums[i] - a) / len;
            if (buckets[index].empty()) {
                buckets[index].push_back(nums[i]);
                buckets[index].push_back(nums[i]);
            } else {
                buckets[index][0] = min(buckets[index][0], nums[i]);
                buckets[index][1] = max(buckets[index][1], nums[i]);
            }
        }
        int gap = 0;
        for (s_t prev = 0, i = 1, iend = buckets.size(); i < iend; ++i) {
            if (buckets[i].empty())
                continue;
            gap = max(gap, buckets[i][0] - buckets[prev][1]);
            prev = i;
        }
        return gap;
    }
};

int main(void)
{
    int array[] = {1,1,1,1,5,5,5,5};
    vector<int> nums(array, array+sizeof(array)/sizeof(int));
    cout << Solution().maximumGap(nums) << endl;
    return 0;
}
