#include <iostream>

using std::endl;
using std::cout;

class Solution {
public:
    int singleNumber(int A[], int n) {
        int ret = A[0];
        for (int i = 1; i < n; i++) {
            ret ^= A[i];
        }
        return ret;
    }
};

int main(void)
{
    int A[] = {1, 2, 2, 3, 3};
    cout << Solution().singleNumber(A, sizeof(A) / sizeof(A[0])) << endl;
    return 0;
}
