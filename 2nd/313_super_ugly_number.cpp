#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ugly(n, 1), indices(primes.size(), 0);
        vector<int> next(primes.size());
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < primes.size(); ++j)
                next[j] = ugly[indices[j]] * primes[j];
            vector<int>::iterator m = min_element(next.begin(), next.end());
            ++indices[m-next.begin()];
            if (*m == ugly[i-1])
                --i;
            else
                ugly[i] = *m;
        }
        return ugly.back();
    }
};

int main(void)
{
    vector<int> primes{2, 7, 13, 19};
    Solution s;
    for (int i = 1; i < 20; ++i) {
        cout << s.nthSuperUglyNumber(i, primes) << endl;
    }
    return 0;
}
