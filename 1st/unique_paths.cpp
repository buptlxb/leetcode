#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (n > m) {
            return factorial(n, m+n-2) / factorial(2, m-1);
        } else {
            return factorial(m, m+n-2) / factorial(2, n-1);
        }
    }
    unsigned long long factorial(int m, int n) {
        unsigned long long ret = 1;
        for (int i = m; i <= n; ++i) {
            ret *= i;
        }
        return ret;
    }
};

int main(void)
{
    cout << Solution().uniquePaths(10, 10) << endl;
    return 0;
}
