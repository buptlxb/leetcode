#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type sz_t;
    int nthUglyNumber(int n) {
        assert(n > 0);
        vector<int> ugs{1};
        for (sz_t i = 0, j = 0, k = 0; n != ugs.size(); ) {
            int cur = min(ugs[i]*2, min(ugs[j]*3, ugs[k]*5));
            if (cur == ugs[i]*2)
                ++i;
            else if (cur == ugs[j]*3)
                ++j;
            else
                ++k;
            if (cur != ugs.back())
                ugs.push_back(cur);
        }
        return ugs.back();
    }
};

int main(void)
{
    Solution s;
    assert(s.nthUglyNumber(10) == 12);
    return 0;
}
