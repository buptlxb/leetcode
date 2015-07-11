#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string candidate = string("123456789").substr(0, n);
        string ret(n, ' ');
        int total = factorial(n);
        for (string::size_type i = 0; i < n; ++i) {
            total /= n-i;
            string::size_type index = (k - 1) / total;
            ret[i] = candidate[index];
            candidate.erase(index, 1);
            k -= total * index;
        }
        return ret;
    }

    int factorial(int n) {
        int ret = 1;
        for (int i = 2; i <= n; ++i) {
            ret *= i;
        }
        return ret;
    }
};

int main(void)
{
    cout << Solution().getPermutation(3, 6) << endl;
    return 0;
}
