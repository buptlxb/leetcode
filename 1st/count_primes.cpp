#include <iostream>

using std::cout;
using std::endl;

class Solution {
public:
    int countPrimes(int n) {
        bool *tag = new bool[n]();
        int *prime = new int[n];
        int cnt = 0;
        for (int i = 2; i < n; ++i) {
            if (!tag[i])
                prime[cnt++] = i;
            for (int j = 0; j < cnt && i * prime[j] < n; ++j) {
                tag[i * prime[j]] = true;
                if (i % prime[j] == 0)
                    break;
            }
        }
        delete []tag;
        delete []prime;
        return cnt;
    }
};

int main(void)
{
    Solution s;
    cout << s.countPrimes(1) << endl;
    cout << s.countPrimes(5) << endl;
    cout << s.countPrimes(10) << endl;
    return 0;
}
