#include <iostream>

using std::cout;
using std::endl;
using std::cin;

class Solution {
public:
    int mySqrt(int x) {
        if (0 == x)
            return 0;
        if (x < 4)
            return 1;
        long long int left = 1;
        long long int right = x / 2;
        while (left < right) {
            long long int mid = (left + right) / 2;
            if (mid * mid == x)
                return mid;
            if (mid * mid < x && (mid + 1) * (mid + 1) > x)
                return mid;
            if (mid * mid > x) {
                right = mid;
            } else {
                left = mid+1;
            }
        }
        return left;
    }
};

int main(void)
{
    int x;
    while (cin >> x)
        cout << Solution().mySqrt(x) << endl;
    return 0;
}
