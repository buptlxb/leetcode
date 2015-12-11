#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> m;
        return isHappy(n, m);
    }
    bool isHappy(int n, unordered_set<int> &m) {
        if (n == 1)           
            return true;
        if (!m.insert(n).second)
            return false;
        int t = 0;
        for (; n; n /= 10) {
            t += (n % 10) * (n % 10);
        }
        return isHappy(t, m);
    }
};

int main(void)
{
    return 0;
}
