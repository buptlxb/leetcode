#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1.0;
        else if (n == 1) {
            return x;
        } else if (n > 1) {
            return myPow(x*x, n/2) * myPow(x, n%2);
        } else {
            return myPow(1/x, -(n+1)) * 1 / x;
        }
    }
};

int main(void)
{
    cout << Solution().myPow(2.6, -7) << endl;
    return 0;
}
