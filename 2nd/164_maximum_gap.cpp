#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2)
            return 0;
        int begin = *min_element(nums.begin(), nums.end());
        int end = *max_element(nums.begin(), nums.end());
        int step = (end - begin) / nums.size() + 1;
        vector<vector<int> > brackets((end - begin) / step + 1);
        for (auto x : nums) {
            int idx = (x - begin) / step;
            if (brackets[idx].empty()) {
                brackets[idx].push_back(x);
                brackets[idx].push_back(x);
            } else {
                brackets[idx][0] = min(brackets[idx][0], x);
                brackets[idx][1] = max(brackets[idx][1], x);
            }
        }
        int gap = 0;
        for (int prev = 0, i = 0, iend = brackets.size(); i < iend; ++i) {
            if (brackets[i].empty())
                continue;
            gap = max(gap, brackets[i][0]-brackets[prev][1]);
            prev = i;
        }
        return gap;
    }
};

int main(void)
{
    return 0;
}
