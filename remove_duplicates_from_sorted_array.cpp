#include <iostream>

using std::cout;
using std::endl;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (!n)
            return 0;
        int index = 1;
        for (int i = 1; i < n; i++) {
            if (A[i] != A[i-1])
                A[index++] = A[i];
        }
        return index;
    }
};

int main(void)
{
    int A[] = {1, 1, 2, 2, 3, 4, 4, 5};
    int len = sizeof(A) / sizeof(A[0]);
    int new_len = Solution().removeDuplicates(A, len);
    for (int i = 0; i < new_len; i++) {
        cout << A[i] << endl;
    }
    return 0;
}
