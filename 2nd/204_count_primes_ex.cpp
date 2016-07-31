#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n < 3)
            return 0;
        int ret = n / 2;
        bool *nums = new bool[n]();
        for (int i = 3; i < sqrt(n); i += 2) {
            if (nums[i])
                continue;
            for (int j = i*i, k = i << 1; j < n; j += k) {
                if (!nums[j]) --ret;
                nums[j] = true;
            }
        }
        return ret;
    }
};

int main(void)
{
    int n;
    Solution s;
    while (cin >> n)
        cout << s.countPrimes(n) << endl;
    return 0;
}
