#include <iostream>

using std::endl;
using std::cout;

class Solution {
public:
    int singleNumber(int A[], int n) {
        int ones(0), twos(0), threes(0);
        for (int i = 0; i < n; i++) {
            twos |= ones & A[i];
            ones ^= A[i];
            threes = (ones & twos);
            ones &= ~threes;
            twos &= ~threes;
        }
        return ones;
    }
};

int main(void)
{
    int A[] = {5, 3, 3, 3};
    cout << Solution().singleNumber(A, sizeof(A) / sizeof(A[0])) << endl;
    return 0;
}
