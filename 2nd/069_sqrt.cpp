#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x < 0)
            return -1;
        if (x == 0 || x == 1)
            return x;
        long long int left = 1;
        long long int right = x / 2;
        while (left < right) {
            long long int mid = left + (right-left) / 2;
            if (mid * mid == x)
                return mid;
            else if (mid * mid > x)
                right = mid;
            else if (mid * mid < x && x < (mid+1)*(mid+1))
                return mid;
            else
                left = mid + 1;
        }
        return left;
    }
};

int main(void)
{
    return 0;
}
