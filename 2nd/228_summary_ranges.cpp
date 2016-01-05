#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        if (nums.empty())
            return ret;
        int cur = 0, j = 0;
        ostringstream os;
        for (int i = 0, iend = nums.size(); i < iend; ++i, ++cur) {
            if (nums[j] + cur != nums[i]) {
                if (cur != 1)
                    os << nums[j] << "->" << nums[j]+cur-1;
                else
                    os << nums[j];
                ret.push_back(os.str());
                os.str("");
                cur = 0;
                j = i;
            }
        }
        if (cur != 1)
            os << nums[j] << "->" << nums[j]+cur-1;
        else
            os << nums[j];
        ret.push_back(os.str());
        return ret;
    }
};

int main(void)
{
    vector<int> nums{0,1,2,4,5,7};
    Solution().summaryRanges(nums);
    return 0;
}
