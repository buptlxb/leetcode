#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string candidates = string("123456789").substr(0, n);
        int total = 1;
        for (int i = 2; i <= n; ++i)
            total *= i;
        string ret(n, 0);
        for (int i = 0; i < n; ++i) {
            total /= n-i;
            int index = (k-1) / total;
            ret[i] = candidates[index];
            candidates.erase(index, 1);
            k -= index * total;
        }
        return ret;
    }
};

int main(void)
{
    return 0;
}
