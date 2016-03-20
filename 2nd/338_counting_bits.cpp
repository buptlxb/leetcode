#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        if (num < 0)
            return vector<int>();
        vector<int> ret(num+1);
        int offset = 1;
        for (int i = 1; i <= num; ++i) {
            if (i >= offset*2)
                offset <<= 1;
            ret[i] = ret[i - offset] + 1;
        }
        return ret;
    }
};

int main(void)
{
    vector<int> ret = Solution().countBits(10);
    for (auto x : ret)
        cout << x << " ";
    cout << endl;
    return 0;
}
