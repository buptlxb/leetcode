#include <iostream>

using std::cout;
using std::endl;

class Solution {
public:
    int numTrees(int n) {
        if (n <= 0)
            return 0;
        int *res = new int[n+1]();
        res[0] = 1;
        res[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                res[i] += res[j]*res[i-j-1];
            }
        }
        int ret = res[n];
        delete [] res;
        return ret;
        //return numTrees(1, n);
    }
    int numTrees(int start, int end) {
        if (start >= end)
            return 1;
        int ret = 0;
        for (int i = start; i <= end; ++i) {
            ret += numTrees(start, i-1)*numTrees(i+1, end);
        }
        return ret;
    }
};

int main(void)
{
    cout << Solution().numTrees(3) << endl;
    return 0;
}
