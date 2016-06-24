#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int gcd(int a, int b) {
        if (a % b == 0)
            return b;
        return gcd(b, a%b);
    }
    bool canMeasureWater(int x, int y, int z) {
        if (z > x && z > y)
            return false;
        if (z == 0)
            return true;
        int t = gcd(x, y);
        return (z % t == 0);
    }
};

int main(void)
{
    Solution s;
    cout << s.canMeasureWater(3, 5, 4) << endl;
    cout << s.canMeasureWater(2, 6, 5) << endl;
    return 0;
}
