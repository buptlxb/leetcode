#include <iostream>

using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i = m + n -1;
        int mi = m-1;
        int ni = n-1;
        while (mi >= 0 && ni >= 0) {
            if (A[mi] > B[ni]) {
                A[i] = A[mi];
                mi--;
            }
            else {
                A[i] = B[ni];
                ni--;
            }
            i--;
        }
        while (mi >= 0) {
            A[i] = A[mi];
            i--;
            mi--;
        }
        while (ni >= 0) {
            A[i] = B[ni];
            i--;
            ni--;
        }
    }
};

int main(void)
{
    int A[] = {1, 3, 4, 0, 0};
    int B[] = {2, 3};
    int m = 3;
    int n = 2;
    Solution().merge(A, m, B, n);
    for (int i = 0; i < m + n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}
