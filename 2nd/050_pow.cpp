#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)
            return 1.0;
        if (x == 0)
            return 0;
        else if (n < 0)
            return myPow(1/x, -(1+n)) / x;
        else if (n == 1)
            return x;
        else if (n > 1)
            return myPow(x*x, n/2) * myPow(x, n%2);
    }
};

int main(void)
{
    return 0;
}
