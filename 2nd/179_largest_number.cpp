#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    struct mygreater : public binary_function<int, int, bool> {
        typedef string::size_type sz_t;
        bool operator() (int lhs, int rhs) {
            ostringstream os1, os2;
            os1 << lhs << rhs;
            os2 << rhs << lhs;
            return os1.str() > os2.str();
        }
    };
    string largestNumber(vector<int>& nums) {
        ostringstream os;
        if (nums.empty())
            return os.str();
        sort(nums.begin(), nums.end(), mygreater());
        for (auto x : nums)
            os << x;
        string ret = os.str();
        string::iterator i, iend;
        for (i = ret.begin(), iend = ret.end(); i != iend && *i == '0'; ++i)
            ;
        if (i == iend)
            return string("0");
        return {i, iend};
    }
};

int main(void)
{
    Solution s;
    vector<int> nums;
    assert(!(nums={3, 30, 34, 5, 9}).empty() && "9534330" == s.largestNumber(nums));
    assert(!(nums={12, 121}).empty() && "12121" == s.largestNumber(nums));
    return 0;
}
