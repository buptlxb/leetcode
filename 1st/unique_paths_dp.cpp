#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int *tmp = new int[n]();
        tmp[0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                tmp[j] += tmp[j-1];
            }
        }
        return tmp[n-1];
    }
};

int main(void)
{
    cout << Solution().uniquePaths(10, 10) << endl;
    return 0;
}
