#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return 10;
        if (n == 2)
            return 91;
        vector<int> f(n+1);
        f[0] = 0; f[1] = 10; f[2] = 81;
        for (int i = 3; i <= n; ++i)
            f[i] = f[i-1] * (9 - i + 2);
        return accumulate(f.begin(), f.end(), 0);
    }
};

int main(void)
{
    Solution s;
    for (int i = 0; i < 10; ++i)
        cout << s.countNumbersWithUniqueDigits(i) << endl;
    return 0;
}
