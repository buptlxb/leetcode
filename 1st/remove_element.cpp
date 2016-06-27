#include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int ret = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] != elem) {
                A[ret++] = A[i];
            }
        }
        return ret;
    }
};

int main(void)
{
    int A[] = {1, 2, 3, 4, 3};
    cout << Solution().removeElement(A, sizeof(A)/sizeof(A[0]), 3) << endl;
    return 0;
}
