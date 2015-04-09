#include <iostream>

using std::cout;
using std::endl;

class Solution {
public:
    int jump(int A[], int n) {
        int ret = 0;
        int last = 0;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (last < i) {
                last = cur;
                ret++;
            }
            if (cur < i + A[i])
                cur = i + A[i];
        }
        return ret;
    }

};

int main(void)
{
    int A[] = {2,3,1,1,4};
    cout << Solution().jump(A, sizeof(A) / sizeof(A[0])) << endl;
    return 0;
}
