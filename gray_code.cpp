#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        ret.push_back(0);
        if (n == 0)
            return ret;
        ret.push_back(1);
        for (int i = 1; i < n; ++i) {
            for (vector<int>::size_type j = 1 << i, jend = 1 << (i+1); j < jend; ++j) {
                ret.push_back(ret[jend-1-j] + (1 << i));
            }
        }
        return ret;
    }
};

int main(void)
{
    vector<int> vec = Solution().grayCode(3);
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;
    return 0;
}
