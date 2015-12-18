#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if (n < 3)
            return 0;
        vector<bool> vec(n, true);
        for (int i = 2; i < n; ++i) {
            if (!vec[i])
                continue;
            for (int j = 2*i; j < n; j += i)
                vec[j] = false;
        }
        return count(vec.begin()+2, vec.end(), true);
    }
};

int main(void)
{
    cout << Solution().countPrimes(1000) << endl;
    return 0;
}
