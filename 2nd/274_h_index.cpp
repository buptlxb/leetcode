#include <iostream>
#include <algorithm>
#include <cassert>
#include <algorithm>

using namespace std;

class Solution {
public:
    typedef vector<int>::size_type sz_t;
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        sz_t ret = 0;
        for (sz_t i = citations.size(); i > 0; --i) {
            ret = max(ret, min(citations.size()-i+1, (sz_t)citations[i-1]));
        }
        return ret;
    }
};

int main(void)
{
    Solution s;
    vector<int> citations{3, 0, 6, 1, 5};
    assert(s.hIndex(citations) == 3);
    return 0;
}
